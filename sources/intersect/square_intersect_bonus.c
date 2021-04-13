/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   square_intersect_bonus.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/21 13:59:01 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:26:17 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <scene.h>
# include <utils.h>
# include <math.h>

t_bool	square_intersect(t_shapes *catch, t_hitrecord *rec)
{
	t_square		*square;
	t_square_vars	vars;

	square = catch->shape;
	vars.pl = vec3_dot(square->normal, rec->ray.dir);
	if (fabs(vars.pl) < M_EPSILON)
		return (false);
	vars.p = vec3_sub(square->origin, rec->ray.origin);
	vars.t = vec3_dot(vars.p, square->normal) / vars.pl;
	if (vars.t < 0)
		return (false);
	vars.point = get_point(rec->ray.origin, rec->ray.dir, vars.t);
	vars.diff = vec3_sub(vars.point, square->origin);
	vars.u = vec3_dot(square->span_a, vars.diff);
	vars.v = vec3_dot(square->span_b, vars.diff);
	if ((fabs(vars.u) > square->size * 0.5 || fabs(vars.v) > square->size * 0.5)
		|| vars.t > rec->distance)
		return (false);
	rec->point = vars.point;
	rec->normal = square->normal;
	if (vars.pl > 0)
		rec->normal = vec3_mult_s(rec->normal, -1);
	rec->tex.u = (vars.u / square->size) + 0.5;
	rec->tex.v = (vars.v / square->size) + 0.5;
	return (hit(catch, rec, vars.t));
}

#endif
