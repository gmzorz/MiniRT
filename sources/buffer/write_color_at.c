/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_color_at.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 15:28:48 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:07:44 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <color.h>
#include <buffer.h>

void	write_color_at(t_buffer *buf, const int u, const int v,
	const t_rgb color)
{
	char		*location;

	location = get_addr_loc(buf, u, v);
	*(unsigned int *)location = rgb_to_data(vec3_clamp(color, 0, 1));
}
