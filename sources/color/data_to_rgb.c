/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   data_to_rgb.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 15:27:19 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:07:57 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <color.h>

t_rgb	data_to_rgb(const unsigned int color)
{
	t_rgb		rgb;

	rgb.x = ((color >> 16) & 0xFF) / 255.0;
	rgb.y = ((color >> 8) & 0xFF) / 255.0;
	rgb.z = ((color) & 0xFF) / 255.0;
	return (rgb);
}
