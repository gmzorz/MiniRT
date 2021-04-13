/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   plane_intersect.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/21 13:59:01 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:52:20 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 0
# include <scene.h>
# include <utils.h>
# include <math.h>

t_bool	plane_intersect(t_shapes *catch, t_hitrecord *rec)
{
	t_plane			*plane;
	t_plane_vars	vars;

	plane = catch->shape;
	vars.pl = vec3_dot(plane->normal, rec->ray.dir);
	if (fabs(vars.pl) < M_EPSILON)
		return (false);
	vars.p = vec3_sub(plane->origin, rec->ray.origin);
	vars.t = vec3_dot(vars.p, plane->normal) / vars.pl;
	if (vars.t <= M_EPSILON || vars.t > rec->distance)
		return (false);
	rec->normal = plane->normal;
	if (vars.pl > 0)
		rec->normal = vec3_mult_s(plane->normal, -1);
	rec->point = get_point(rec->ray.origin, rec->ray.dir, vars.t);
	rec->ref = catch;
	rec->distance = vars.t;
	return (true);
}

#endif
