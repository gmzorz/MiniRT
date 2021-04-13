/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   aabb.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/14 14:45:10 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 17:58:16 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <shapes.h>
#include <math.h>

static t_real	max(t_real one, t_real two)
{
	if (one < two)
		return (two);
	return (one);
}

static t_real	min(t_real one, t_real two)
{
	if (one > two)
		return (two);
	return (one);
}

t_bool	volume_centroid(t_aabb *volume)
{
	volume->centroid = vec3_add(vec3_mult_s(vec3_sub(
					volume->max, volume->min), 0.5), volume->min);
	return (true);
}

t_bool	volume_add_vec(t_aabb *volume, t_vec3 vec)
{
	volume->min = (t_vec3){
		min(volume->min.x, vec.x),
		min(volume->min.y, vec.y),
		min(volume->min.z, vec.z)};
	volume->max = (t_vec3){
		max(volume->max.x, vec.x),
		max(volume->max.y, vec.y),
		max(volume->max.z, vec.z)};
	return (true);
}
