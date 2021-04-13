/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rgb_to_data.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 15:32:53 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:07:52 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <color.h>

unsigned int	rgb_to_data(const t_rgb color)
{
	int		r;
	int		g;
	int		b;

	r = (double)(color.x * 255);
	g = (double)(color.y * 255);
	b = (double)(color.z * 255);
	return (r << 16 | g << 8 | b);
}
