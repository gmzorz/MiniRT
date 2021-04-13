/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shape_translate_set_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/22 13:47:06 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:49:10 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <events.h>

t_bool	sh_trans_set_rot(t_scene *scene)
{
	if (scene->selected_shape == NULL)
		return (false);
	scene->selection_mode = SELECTION_ROTATE;
	scene->do_update = true;
	console_put(SET_TRANS_MODE_R);
	return (true);
}

t_bool	sh_trans_set_pos(t_scene *scene)
{
	if (scene->selected_shape == NULL)
		return (false);
	scene->selection_mode = SELECTION_TRANSLATE;
	scene->do_update = true;
	console_put(SET_TRANS_MODE_T);
	return (true);
}
