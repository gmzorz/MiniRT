/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_uvs_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/13 14:50:50 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:44:53 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_bool	render_uvs(t_scene *scene)
{
	scene->viewport = uvs;
	console_put(DEBUG_UV);
	return (true);
}
