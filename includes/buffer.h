/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   buffer.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:37:01 by goosterl      #+#    #+#                 */
/*   Updated: 2021/03/25 14:22:25 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_H
# define BUFFER_H
# include <mlx.h>
# include <alias.h>
# include <vector.h>

/*
**	MLX buffer
**	 type		- Buffer type (refer to buffer.h/e_buftype)
**	 image		- (*) Image buffer
**	 address	- (*) Address of image buffer
**	 width		- (*) Image width (in pixels)
**	 height		- (*) Image height (in pixels)
**	 bpp		- (*) Bits per pixel
**	 endian		- (*) Endianness
**	(*): Declaration (may be) applied by minilibx 
*/
typedef struct s_buffer
{
	void		*image;
	void		*address;
	int			size;
	int			width;
	int			height;
	int			bpp;
	int			row_size;
	int			endian;
	t_bool		de_gamma;
}	t_buffer;

typedef struct s_window
{
	void		*ptr;
	void		*win;
	int			width;
	int			height;
}	t_window;

typedef enum e_buftype
{
	b_missing,
	b_image,
	b_texture,
	b_filter,
	b_debug
}	t_buftype;

/*
**	initialize a new empty image buffer
*/
t_bool	new_buffer(t_buffer *buf, void *mlx_ptr,
			const int width, const int height);

/*
**	Destroy image buffer
*/
t_bool	destroy_buffer(t_buffer *buf, void *mlx_ptr);

/*
**	retrieve 8 bytes representing pixel information from image buffer at [u & v]
*/
char	*get_addr_loc(const t_buffer *buf, const int u, const int v);

/*
**	retrieve pixel information in vec3 format
*/
t_vec3	get_color_at(const t_buffer *buf, const int u, const int v);

/*
**	write pixel information using vec3 format
*/
void	write_color_at(t_buffer *buf, const int u, const int v,
			const t_vec3 color);

t_bool	copy_buffer(t_buffer *in, void *mlx_ptr, t_buffer *out);

#endif