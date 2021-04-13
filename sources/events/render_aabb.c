/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_aabb.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/18 13:11:08 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:39:55 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_bool	render_aabb(t_scene *scene)
{
	console_put(DEBUG_AABB);
	scene->viewport = aabb;
	return (true);
}
