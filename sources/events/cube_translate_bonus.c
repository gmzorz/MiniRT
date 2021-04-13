/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cube_translate_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/22 15:03:01 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:50:58 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>

t_bool	cube_translate(t_scene *scene)
{
	t_cube	*cube;
	t_mat4	orient;

	cube = (t_cube *)scene->selected_shape->shape;
	orient = mat4(cube->origin, cube->span_b, cube->span_a, cube->normal);
	if (scene->selection_mode == SELECTION_TRANSLATE)
		return (translate(scene, &cube->origin));
	if (scene->selection_mode == SELECTION_ROTATE)
	{
		rotate(scene, &orient);
		cube->normal = vec3_unit(mat4_get(orient, m_up));
		cube->span_a = vec3_unit(mat4_get(orient, m_right));
		cube->span_b = vec3_unit(mat4_get(orient, m_forward));
	}
	return (true);
}
