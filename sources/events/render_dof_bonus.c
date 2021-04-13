/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_dof_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/12 15:22:14 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:45:02 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_bool	render_dof(t_scene *scene)
{
	if (scene->camera->dof.enable == false)
		return (false);
	scene->viewport = dof;
	console_put(DEBUG_DOF);
	return (true);
}
