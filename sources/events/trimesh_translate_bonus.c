/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   trimesh_translate_bonus.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/10 16:25:15 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 17:54:05 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>
#include <libft.h>
#include <init.h>

static t_bool	trimesh_rotate(t_scene *scene, t_trimesh *mesh)
{
	const t_vec3	identity = (t_vec3){SHAPE_ROT, SHAPE_ROT, SHAPE_ROT};
	t_vec3			mult;
	t_mat4			orient;
	int				idx;

	mult = vec3_mult(identity, scene->selection_axis);
	idx = 0;
	volume_init(&mesh->volume);
	while (idx < mesh->verts)
	{
		ft_memset(&orient, 0, sizeof(t_mat4));
		orient = mat4_add_vec(orient, mesh->vert[idx].point);
		orient = mat4_rota(orient, mesh->centroid, mult);
		mesh->vert[idx].point = mat4_get(orient, m_origin);
		volume_add_vec(&mesh->volume, mesh->vert[idx].point);
		idx += 1;
	}
	return (true);
}

t_bool	trimesh_translate(t_scene *scene)
{
	t_trimesh	*mesh;

	mesh = (t_trimesh *)scene->selected_shape->shape;
	if (scene->selection_mode == SELECTION_TRANSLATE)
	{
		mesh->construct = true;
		translate(scene, &mesh->origin);
		return (true);
	}
	if (scene->selection_mode == SELECTION_ROTATE)
	{
		mesh->construct = true;
		return (trimesh_rotate(scene, mesh));
	}
	return (true);
}
