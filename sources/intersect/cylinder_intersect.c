/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cylinder_intersect.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/22 15:04:15 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:52:45 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 0
# include <scene.h>
# include <math.h>
# include <utils.h>

/*
**	Solve quadratics based on ray world coordinates (not axis aligned)
*/

static void	cylinder_quad(t_cylinder_vars *vars, t_hitrecord *rec,
	t_cylinder *cyl)
{
	t_vec3		dist_to_top;
	t_vec3		dtt_x_diff;
	t_vec3		rd_x_diff;
	t_real		radius_ofs;

	dist_to_top = vec3_sub(rec->ray.origin, cyl->top);
	dtt_x_diff = vec3_cross(dist_to_top, cyl->diff);
	rd_x_diff = vec3_cross(rec->ray.dir, cyl->diff);
	radius_ofs = vec3_dot(cyl->diff, cyl->diff);
	vars->a = vec3_dot(rd_x_diff, rd_x_diff);
	vars->b = 2 * vec3_dot(rd_x_diff, dtt_x_diff);
	vars->c = vec3_dot(dtt_x_diff, dtt_x_diff)
		- (cyl->radius * cyl->radius * radius_ofs);
	vars->d = vars->b * vars->b - 4 * vars->a * vars->c;
	vars->d_sqr = sqrt(vars->d);
	vars->a_2 = vars->a * 2;
}

static t_bool	cylinder_height(t_shapes *catch, t_hitrecord *rec, t_real t,
	t_bool inside)
{
	t_cylinder	*cyl;
	t_vec3		point;
	t_vec3		origin_diff;
	t_real		dist_to_point;
	t_vec3		point_centroid;

	cyl = catch->shape;
	point = get_point(rec->ray.origin, rec->ray.dir, t);
	origin_diff = vec3_sub(cyl->origin, point);
	dist_to_point = vec3_dot(origin_diff, cyl->normal);
	if (fabs(dist_to_point) > cyl->height_d2)
		return (false);
	point_centroid = get_point(cyl->origin, cyl->normal, -dist_to_point);
	rec->distance = t;
	rec->point = point;
	rec->normal = vec3_unit(vec3_sub(point, point_centroid));
	if (inside)
		rec->normal = vec3_negate(rec->normal);
	rec->ref = catch;
	return (true);
}

t_bool	cylinder_intersect(t_shapes *catch, t_hitrecord *rec)
{
	t_cylinder		*cyl;
	t_cylinder_vars	vars;
	t_real			t[2];

	cyl = catch->shape;
	cylinder_quad(&vars, rec, cyl);
	if (vars.d < 0)
		return (false);
	t[0] = (-vars.b - vars.d_sqr) / vars.a_2;
	if (t[0] >= 0 && t[0] <= rec->distance
		&& cylinder_height(catch, rec, t[0], false))
		return (true);
	t[1] = (-vars.b + vars.d_sqr) / vars.a_2;
	if (t[1] >= 0 && t[1] <= rec->distance
		&& cylinder_height(catch, rec, t[1], true))
		return (true);
	return (false);
}

#endif
