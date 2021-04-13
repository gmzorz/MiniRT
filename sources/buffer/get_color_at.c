/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_color_at.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 15:20:26 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:06:22 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <color.h>
#include <buffer.h>
#include <unistd.h>

t_rgb	get_color_at(const t_buffer *buf, const int u, const int v)
{
	char	*location;

	location = get_addr_loc(buf, u, v);
	if (location == NULL)
		return (vec3_zero());
	return (data_to_rgb(*(unsigned int *)location));
}
