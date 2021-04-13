/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   deselect_bonus.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/22 14:08:28 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:49:57 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <events.h>

t_bool	sh_deselect(t_scene *scene)
{
	if (scene->selected_shape || scene->selection_mode)
	{
		console_put(SH_DESELECT);
		scene->selected_shape = NULL;
		scene->selection_mode = SELECTION_UNDEFINED;
		scene->selection_axis = vec3_zero();
		scene->do_update = true;
	}
	return (true);
}
