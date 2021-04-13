/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_units_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/12 12:04:17 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:44:46 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_bool	render_units(t_scene *scene)
{
	scene->viewport = units;
	console_put(DEBUG_UNITS);
	return (true);
}
