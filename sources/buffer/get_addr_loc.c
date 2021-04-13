/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_addr_loc.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 15:07:44 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:06:22 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <buffer.h>

char	*get_addr_loc(const t_buffer *buf, const int u, const int v)
{
	char	*location;

	location = buf->address
		+ (v * buf->row_size
			+ u * (buf->bpp / COLOR_SIZE));
	return (location);
}
