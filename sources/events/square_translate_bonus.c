/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   square_translate_bonus.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/23 11:07:47 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:51:22 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>

t_bool	square_translate(t_scene *scene)
{
	t_square	*sq;
	t_mat4		orient;

	sq = (t_square *)scene->selected_shape->shape;
	if (scene->selection_mode == SELECTION_TRANSLATE)
		return (translate(scene, &sq->origin));
	if (scene->selection_mode == SELECTION_ROTATE)
	{
		orient = mat4(sq->origin, sq->span_b, sq->span_a, sq->normal);
		rotate(scene, &orient);
		sq->normal = vec3_unit(mat4_get(orient, m_up));
		sq->span_a = vec3_unit(mat4_get(orient, m_right));
		sq->span_b = vec3_unit(mat4_get(orient, m_forward));
	}
	return (true);
}
