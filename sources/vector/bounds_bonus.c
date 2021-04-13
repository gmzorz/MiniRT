/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bounds_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/12 11:47:43 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:56:16 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>
#include <shapes.h>

t_bool	vec3_is_bounds(const t_vec3 in, const t_aabb volume)
{
	if (in.x >= volume.min.x
		&& in.y >= volume.min.y
		&& in.z >= volume.min.z
		&& in.x <= volume.max.x
		&& in.y <= volume.max.y
		&& in.z <= volume.max.z)
		return (true);
	return (false);
}
