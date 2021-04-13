/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   disk_translate_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/23 11:47:16 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:51:38 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>

t_bool	disk_translate(t_scene *scene)
{
	t_disk	*disk;
	t_mat4	orient;

	disk = (t_disk *)scene->selected_shape->shape;
	orient = mat4(disk->origin, disk->span_b, disk->span_a, disk->normal);
	if (scene->selection_mode == SELECTION_TRANSLATE)
		return (translate(scene, &disk->origin));
	if (scene->selection_mode == SELECTION_ROTATE)
	{
		rotate(scene, &orient);
		disk->normal = vec3_unit(mat4_get(orient, m_up));
		disk->span_a = vec3_unit(mat4_get(orient, m_right));
		disk->span_b = vec3_unit(mat4_get(orient, m_forward));
	}
	return (true);
}
