/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   plane_translate_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/23 10:55:21 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:51:02 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>

t_bool	plane_translate(t_scene *scene)
{
	t_plane	*plane;
	t_mat4	orient;

	plane = (t_plane *)scene->selected_shape->shape;
	orient = mat4(plane->origin, plane->span_b, plane->span_a, plane->normal);
	if (scene->selection_mode == SELECTION_TRANSLATE)
		return (translate(scene, &plane->origin));
	if (scene->selection_mode == SELECTION_ROTATE)
	{
		rotate(scene, &orient);
		plane->normal = vec3_unit(mat4_get(orient, m_up));
		plane->span_a = vec3_unit(mat4_get(orient, m_right));
		plane->span_b = vec3_unit(mat4_get(orient, m_forward));
	}
	return (true);
}
