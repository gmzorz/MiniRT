/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   triangle_intersect_bonus.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/23 11:50:39 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:26:29 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <math.h>
# include <scene.h>
# include <utils.h>

static t_bool	triangle_test(t_triangle *tri, t_triangle_vars *vars, int abc)
{
	t_vec3		diff;
	t_real		test;

	diff = vec3_sub(vars->p, tri->vert[abc]);
	test = vec3_dot(tri->normal, vec3_cross(tri->edge[abc], diff));
	if (test < 0)
		return (false);
	if (abc == 1)
		vars->u = test * tri->denom;
	if (abc == 2)
		vars->v = test * tri->denom;
	return (true);
}

t_bool	triangle_intersect(t_shapes *catch, t_hitrecord *rec)
{
	t_triangle		*tri;
	t_triangle_vars	vars;

	tri = catch->shape;
	vars.pl = vec3_dot(tri->normal, rec->ray.dir);
	if (fabs(vars.pl) < M_EPSILON)
		return (false);
	vars.t = - (vec3_dot(tri->normal, rec->ray.origin) + tri->traverse)
		/ vars.pl;
	if (vars.t < M_EPSILON || vars.t > rec->distance)
		return (false);
	vars.p = get_point(rec->ray.origin, rec->ray.dir, vars.t);
	if (!triangle_test(tri, &vars, 0)
		|| !triangle_test(tri, &vars, 1)
		|| !triangle_test(tri, &vars, 2))
		return (false);
	rec->tex.u = vars.u;
	rec->tex.v = vars.v;
	rec->normal = vec3_unit(tri->normal);
	if (vars.pl > 0)
		rec->normal = vec3_negate(rec->normal);
	rec->point = vars.p;
	return (hit(catch, rec, vars.t));
}

#endif
