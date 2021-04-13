/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   plane_construct_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/21 14:40:59 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:24:30 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <scene.h>
# include <utils.h>

t_bool	plane_construct(t_shapes *catch)
{
	t_plane		*plane;

	plane = catch->shape;
	if (vec3_cmp_s(plane->span_a, 0.0))
		vec3_local_coords(plane->normal, &plane->span_a, &plane->span_b);
	catch->volume.using = false;
	return (true);
}

#endif
