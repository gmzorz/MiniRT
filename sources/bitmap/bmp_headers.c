/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bmp_headers.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/06 13:32:45 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:38:46 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <buffer.h>
#include <utils.h>
#include <unistd.h>

/*
**	write_bin is used to write binary data
**	write_def is used to write address data
*/

/*
**	DIB (Device independent bitmap) header (40 bytes)
*/

t_bool	write_dib_header(t_buffer *buf, int fd)
{
	t_bool	check;

	check = true;
	write_bin(&check, fd, (uint32_t *) DIB_SIZE, 4);
	write_def(&check, fd, &buf->width, 4);
	write_def(&check, fd, &buf->height, 4);
	write_bin(&check, fd, (short *) 1, 2);
	write_bin(&check, fd, (short *) 32, 2);
	write_bin(&check, fd, (uint32_t *) 0x0, 4);
	write_bin(&check, fd, (uint32_t *) 64, 4);
	write_bin(&check, fd, (uint32_t *) 0, 4);
	write_bin(&check, fd, (uint32_t *) 0, 4);
	write_bin(&check, fd, (uint32_t *) 256, 4);
	write_bin(&check, fd, (uint32_t *) 0, 4);
	return (check);
}

/*
**	Main BMP header (14 bytes)
*/

t_bool	write_bmp_header(t_buffer *buf, int fd)
{
	uint32_t	file_size;
	t_bool		check;

	check = true;
	file_size = BMP_HEADER_SIZE + DIB_SIZE
		+ (buf->width * buf->height * PIXEL_SIZE);
	write_bin(&check, fd, (unsigned char *) 'B', 1);
	write_bin(&check, fd, (unsigned char *) 'M', 1);
	write_def(&check, fd, &file_size, 4);
	write_bin(&check, fd, (short *) 0x0, 2);
	write_bin(&check, fd, (short *) 0x0, 2);
	write_bin(&check, fd, (uint32_t *) 54, 4);
	return (check);
}
