/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sphere_translate_bonus.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/23 11:02:47 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:51:12 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>

t_bool	sphere_translate(t_scene *scene)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)scene->selected_shape->shape;
	if (scene->selection_mode == SELECTION_TRANSLATE)
		return (translate(scene, &sphere->origin));
	return (true);
}
