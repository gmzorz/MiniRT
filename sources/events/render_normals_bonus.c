/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_normals_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/12 12:04:17 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:44:39 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_bool	render_normals(t_scene *scene)
{
	scene->viewport = normals;
	console_put(DEBUG_NORMALS);
	return (true);
}
