/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   triangle_construct.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/23 11:50:54 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:52:53 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 0
# include <scene.h>
# include <init.h>

t_bool	triangle_construct(t_shapes *catch)
{
	t_triangle	*tri;

	tri = catch->shape;
	tri->edge[0] = vec3_sub(tri->vert[1], tri->vert[0]);
	tri->edge[1] = vec3_sub(tri->vert[2], tri->vert[1]);
	tri->edge[2] = vec3_sub(tri->vert[0], tri->vert[2]);
	tri->normal = vec3_unit(vec3_cross(tri->edge[2], tri->edge[0]));
	tri->traverse = -vec3_dot(tri->normal, tri->vert[0]);
	volume_init(&catch->volume);
	volume_add_vec(&catch->volume, tri->vert[0]);
	volume_add_vec(&catch->volume, tri->vert[1]);
	volume_add_vec(&catch->volume, tri->vert[2]);
	return (true);
}

#endif
