/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 15:14:02 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:10:11 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <color.h>

t_bool	check_color(const t_rgb color)
{
	return ((color.x > 0 || color.x < 1.0)
		&& (color.y > 0 || color.y < 1.0)
		&& (color.z > 0 || color.z < 1.0));
}
