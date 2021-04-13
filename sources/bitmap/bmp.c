/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bmp.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/02 11:28:42 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/13 11:30:19 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <buffer.h>
#include <stdlib.h>
#include <fcntl.h>
#include <error.h>
#include <bitmap.h>
#include <unistd.h>
#include <minirt.h>

static t_bool	free_pixels(uint32_t *pixels, t_bool condition)
{
	free(pixels);
	return (condition);
}

static t_bool	write_bmp_buffer(t_buffer *buf, int fd)
{
	int			u;
	int			v;
	uint32_t	*pixels;
	size_t		loc;

	u = 0;
	v = buf->height - 1;
	pixels = (uint32_t *)malloc(buf->height * buf->width * 4);
	if (pixels == NULL)
		return (0);
	while (v >= 0)
	{
		while (u < buf->width)
		{
			loc = (buf->height - (v + 1)) * buf->width + u;
			pixels[loc] = rgb_to_data(get_color_at(buf, u, v));
			u += 1;
		}
		u = 0;
		v -= 1;
	}
	if (write(fd, pixels, buf->height * buf->width * 4) < 0)
		return (free_pixels(pixels, false));
	return (free_pixels(pixels, true));
}

t_bool	save_bmp(t_buffer *buf, char *filename)
{
	int		fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC | O_APPEND);
	if (fd == -1)
		return (error_msg(ERR_WRONG_FD));
	if (!(write_bmp_header(buf, fd) && write_dib_header(buf, fd)))
		return (error_close_fd(fd, ERR_BMP_HEADER));
	if (!write_bmp_buffer(buf, fd))
		return (error_close_fd(fd, ERR_BMP_BUFFER));
	close(fd);
	return (true);
}
