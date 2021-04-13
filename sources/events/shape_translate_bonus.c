/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shape_translate_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/22 13:47:57 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:49:41 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <jump_tables.h>

static void	vec3_setdir(t_vec3 *vec, t_bool positive)
{
	if (positive)
	{
		if (vec->x == -1.0)
			vec->x = 1.0;
		if (vec->y == -1.0)
			vec->y = 1.0;
		if (vec->z == -1.0)
			vec->z = 1.0;
	}
	else
	{
		if (vec->x == 1.0)
			vec->x = -1.0;
		if (vec->y == 1.0)
			vec->y = -1.0;
		if (vec->z == 1.0)
			vec->z = -1.0;
	}
}

t_bool	sh_translate_up(t_scene *scene)
{
	if (scene->selection_mode == SELECTION_UNDEFINED
		|| vec3_cmp(scene->selection_axis, vec3_zero()))
		return (false);
	scene->selected_shape->construct = true;
	scene->do_update = true;
	vec3_setdir(&scene->selection_axis, false);
	return (jump_translate(scene));
}

t_bool	sh_translate_dn(t_scene *scene)
{
	if (scene->selection_mode == SELECTION_UNDEFINED
		|| vec3_cmp(scene->selection_axis, vec3_zero()))
		return (false);
	scene->selected_shape->construct = true;
	scene->do_update = true;
	vec3_setdir(&scene->selection_axis, true);
	return (jump_translate(scene));
}
