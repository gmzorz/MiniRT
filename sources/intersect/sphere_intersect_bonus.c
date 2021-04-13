/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sphere_intersect_bonus.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/15 16:30:42 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:25:52 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <scene.h>
# include <utils.h>
# include <math.h>

/*
**	Sphere intersection
**	refer to <shapes.h> / s_sphere_vars for variables
**	 d = previous intersection, or M_INFINITY if not previously intersected
**	Calculate the following variables:
**	 t = (So - Ro) • Rd
**	 p = Ro + (Rd * t)
**	 y = û = (So - p)
**	(y > Sr) ? ray misses
**	 x = √(Sr² - y²)
**	 t1 = t - x
**	(t1 > 0 & t1 < d) ? ray intersects
**	 t2 = t + x
**	(t2 > 0 & t2 < d) ? ray intersects inside of sphere
**	 ray misses
*/

static t_bool	sphere_hit(t_shapes *catch, t_hitrecord *rec, t_real t,
	t_bool inside)
{
	t_sphere	*sphere;

	sphere = catch->shape;
	rec->ref = catch;
	rec->distance = t;
	rec->point = get_point(rec->ray.origin, rec->ray.dir, rec->distance);
	rec->normal = vec3_unit(vec3_sub(rec->point, sphere->origin));
	if (inside)
		rec->normal = vec3_mult_s(rec->normal, -1);
	rec->tex.u = 0.5 + atan2(rec->normal.z, rec->normal.x) / (PI_2);
	rec->tex.v = 0.5 - asin(rec->normal.y) / M_PI;
	return (true);
}

t_bool	sphere_intersect(t_shapes *catch, t_hitrecord *rec)
{
	t_sphere		*sphere;
	t_sphere_vars	vars;

	sphere = catch->shape;
	vars.t = vec3_dot(vec3_sub(sphere->origin, rec->ray.origin), rec->ray.dir);
	vars.p = get_point(rec->ray.origin, rec->ray.dir, vars.t);
	vars.y = vec3_mag(vec3_sub(sphere->origin, vars.p));
	if (vars.y > sphere->radius)
		return (false);
	vars.x = sqrt(pow_2(sphere->radius) - pow_2(vars.y));
	vars.t1 = vars.t - vars.x;
	if (vars.t1 > M_EPSILON && vars.t1 < rec->distance)
		return (sphere_hit(catch, rec, vars.t1, false));
	vars.t2 = vars.t + vars.x;
	if (vars.t2 > M_EPSILON && vars.t2 < rec->distance)
		return (sphere_hit(catch, rec, vars.t2, true));
	return (false);
}

#endif
