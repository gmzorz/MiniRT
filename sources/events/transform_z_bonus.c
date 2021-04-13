/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   transform_z_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 15:44:58 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:44:16 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>

t_bool	move_forward(t_scene *scene)
{
	t_vec3		foward;

	foward = mat4_get(scene->camera->world, m_forward);
	foward = vec3_mult_s(foward, CAM_MOVE);
	scene->camera->world = mat4_add_vec(scene->camera->world, foward);
	return (true);
}

t_bool	move_back(t_scene *scene)
{
	t_vec3		back;

	back = mat4_get(scene->camera->world, m_forward);
	back = vec3_mult_s(back, -CAM_MOVE);
	scene->camera->world = mat4_add_vec(scene->camera->world, back);
	return (true);
}

t_bool	roll_right(t_scene *scene)
{
	scene->camera->world = mat4_mult(mat4_rotz(CAM_LOOK),
			scene->camera->world);
	return (true);
}

t_bool	roll_left(t_scene *scene)
{
	scene->camera->world = mat4_mult(mat4_rotz(-CAM_LOOK),
			scene->camera->world);
	return (true);
}
