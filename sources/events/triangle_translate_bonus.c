/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   triangle_translate_bonus.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/23 12:31:44 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 17:54:46 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>
#include <libft.h>

static t_bool	triangle_rotate(t_scene *scene, t_triangle *tri)
{
	const t_vec3	identity = (t_vec3){SHAPE_ROT, SHAPE_ROT, SHAPE_ROT};
	t_mat4			orient[3];
	t_vec3			centroid;
	t_vec3			mult;
	int				idx;

	mult = vec3_mult(identity, scene->selection_axis);
	centroid = vec3_add(vec3_add(tri->vert[0], tri->vert[1]), tri->vert[2]);
	centroid = vec3_div_s(centroid, 3);
	ft_memset(orient, 0, sizeof(t_mat4) * 3);
	idx = 0;
	while (idx < 3)
	{
		orient[idx] = mat4_add_vec(orient[idx], tri->vert[idx]);
		orient[idx] = mat4_rota(orient[idx], centroid, mult);
		tri->vert[idx] = mat4_get(orient[idx], m_origin);
		idx += 1;
	}
	return (true);
}

t_bool	triangle_translate(t_scene *scene)
{
	t_triangle	*tri;

	tri = (t_triangle *)scene->selected_shape->shape;
	if (scene->selection_mode == SELECTION_TRANSLATE)
	{
		translate(scene, &tri->vert[0]);
		translate(scene, &tri->vert[1]);
		translate(scene, &tri->vert[2]);
		return (true);
	}
	if (scene->selection_mode == SELECTION_ROTATE)
		return (triangle_rotate(scene, tri));
	return (true);
}
