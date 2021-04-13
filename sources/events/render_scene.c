/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_scene.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/10 13:01:42 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:40:01 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_bool	render_scene(t_scene *scene)
{
	console_put(RT_RENDER);
	scene->viewport = shaded;
	return (true);
}
