/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pyramid_translate_bonus.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/23 15:12:34 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:51:54 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>

t_bool	pyramid_translate(t_scene *scene)
{
	t_pyramid	*pyr;
	t_mat4		orient;

	pyr = (t_pyramid *)scene->selected_shape->shape;
	if (scene->selection_mode == SELECTION_TRANSLATE)
		return (translate(scene, &pyr->origin));
	if (scene->selection_mode == SELECTION_ROTATE)
	{
		orient = mat4(pyr->origin, pyr->span_b, pyr->span_a, pyr->normal);
		rotate(scene, &orient);
		pyr->normal = vec3_unit(mat4_get(orient, m_up));
		pyr->span_a = vec3_unit(mat4_get(orient, m_right));
		pyr->span_b = vec3_unit(mat4_get(orient, m_forward));
	}
	return (true);
}
