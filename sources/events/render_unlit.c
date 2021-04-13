/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_unlit.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/13 15:38:53 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:39:51 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_bool	render_unlit(t_scene *scene)
{
	scene->viewport = unlit;
	console_put(DEBUG_UNLIT);
	return (true);
}
