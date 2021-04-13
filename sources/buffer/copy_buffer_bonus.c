/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   copy_buffer_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/08 15:12:10 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:37:35 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <buffer.h>

t_bool	copy_buffer(t_buffer *in, void *mlx_ptr, t_buffer *out)
{
	int		u;
	int		v;

	u = 0;
	v = 0;
	if (mlx_ptr)
	{
		if (new_buffer(out, mlx_ptr, in->width, in->height) == false)
			return (false);
	}
	while (u < in->width)
	{
		while (v < in->height)
		{
			write_color_at(out, u, v, get_color_at(in, u, v));
			v += 1;
		}
		v = 0;
		u += 1;
	}
	return (true);
}
