/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   transform_x_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 15:44:58 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:44:05 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>

t_bool	move_right(t_scene *scene)
{
	t_vec3		right;

	right = mat4_get(scene->camera->world, m_right);
	right = vec3_mult_s(right, CAM_MOVE);
	scene->camera->world = mat4_add_vec(scene->camera->world, right);
	return (true);
}

t_bool	move_left(t_scene *scene)
{
	t_vec3		left;

	left = mat4_get(scene->camera->world, m_right);
	left = vec3_mult_s(left, -CAM_MOVE);
	scene->camera->world = mat4_add_vec(scene->camera->world, left);
	return (true);
}

t_bool	pitch_up(t_scene *scene)
{
	scene->camera->world = mat4_mult(mat4_rotx(CAM_LOOK),
			scene->camera->world);
	return (true);
}

t_bool	pitch_down(t_scene *scene)
{
	scene->camera->world = mat4_mult(mat4_rotx(-CAM_LOOK),
			scene->camera->world);
	return (true);
}
