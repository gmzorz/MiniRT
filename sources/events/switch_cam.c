/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   switch_cam.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/10 16:25:23 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/13 12:31:57 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <error.h>
#include <minirt.h>
#include <events.h>

t_bool	next_cam(t_scene *scene)
{
	t_camlist		*list;

	if (scene->cam_idx < scene->cam_count)
		scene->cam_idx += 1;
	else
		return (true);
	console_put(CAM_SWITCH_N);
	list = scene->cameras;
	while (list->id < scene->cam_idx)
		list = list->next;
	scene->camera = list->cam;
	if (scene->camera == NULL)
		return (error_msg(ERR_ALLOC_CAM));
	return (true);
}

t_bool	prev_cam(t_scene *scene)
{
	t_camlist		*list;

	if (scene->cam_idx != 1)
		scene->cam_idx -= 1;
	else
		return (true);
	console_put(CAM_SWITCH_P);
	list = scene->cameras;
	while (list->id < scene->cam_idx)
		list = list->next;
	scene->camera = list->cam;
	if (scene->camera == NULL)
		return (error_msg(ERR_ALLOC_CAM));
	return (true);
}
