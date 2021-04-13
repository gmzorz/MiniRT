/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fov_adjust_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/26 16:55:46 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:52:38 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <events.h>

t_bool	fov_increase(t_scene *scene)
{
	scene->camera->fov += FOV_SCALAR;
	scene->do_update = true;
	scene->camera->view_range = tan((scene->camera->fov * 0.5) * (M_PI / 180));
	return (true);
}

t_bool	fov_decrease(t_scene *scene)
{
	scene->camera->fov -= FOV_SCALAR;
	scene->do_update = true;
	scene->camera->view_range = tan((scene->camera->fov * 0.5) * (M_PI / 180));
	return (true);
}
