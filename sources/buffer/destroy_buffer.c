/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   destroy_buffer.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/06 14:38:17 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:07:01 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <buffer.h>
#include <libft.h>

t_bool	destroy_buffer(t_buffer *buf, void *mlx_ptr)
{
	mlx_destroy_image(mlx_ptr, buf->image);
	ft_memset(&buf, 0, sizeof(t_buffer *));
	return (true);
}
