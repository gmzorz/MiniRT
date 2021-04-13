/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_buffer.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 15:48:20 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:06:49 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <buffer.h>
#include <unistd.h>
#include <error.h>

t_bool	new_buffer(t_buffer *buf, void *mlx_ptr,
	const int width, const int height)
{
	buf->width = width;
	buf->height = height;
	buf->image = mlx_new_image(mlx_ptr, width, height);
	if (buf->image == NULL)
		return (error_set_null(buf, "Failed to load image into buffer"));
	buf->address = mlx_get_data_addr(buf->image,
			&buf->bpp, &buf->row_size, &buf->endian);
	buf->size = buf->width * buf->row_size + buf->height * 4;
	return (true);
}
