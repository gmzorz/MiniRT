/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dof_adjust_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/26 14:16:48 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/13 11:50:24 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>
#include <events.h>

t_bool	dof_adjust_dn(t_scene *scene)
{
	scene->do_update = false;
	if (scene->viewport != dof)
		return (false);
	scene->do_update = true;
	scene->camera->dof.focal_dist -= DOF_DIST_SCALE;
	return (true);
}

t_bool	dof_adjust_up(t_scene *scene)
{
	scene->do_update = false;
	if (scene->viewport != dof)
		return (false);
	scene->do_update = true;
	scene->camera->dof.focal_dist += DOF_DIST_SCALE;
	return (true);
}
