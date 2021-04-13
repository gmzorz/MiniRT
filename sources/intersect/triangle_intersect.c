/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   triangle_intersect.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/23 11:50:39 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:52:59 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 0
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
	rec->normal = tri->normal;
	if (vars.pl > 0)
		rec->normal = vec3_mult_s(rec->normal, -1);
	rec->point = vars.p;
	return (hit(catch, rec, vars.t));
}

#endif
