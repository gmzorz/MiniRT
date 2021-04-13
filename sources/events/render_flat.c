/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_flat.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/13 15:38:00 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:39:47 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_bool	render_flat(t_scene *scene)
{
	console_put(DEBUG_FLAT);
	scene->viewport = flat;
	return (true);
}
