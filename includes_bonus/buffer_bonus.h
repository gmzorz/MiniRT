/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   buffer_bonus.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:37:01 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:14:44 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_BONUS_H
# define BUFFER_BONUS_H
# if IS_BONUS == 1

/*
**	initialize a new image buffer using a xpm reference
**	buffer type will be set to b_missing if the image file cannot be found
*/
t_bool	new_tex_buffer(t_buffer *buf, void *mlx_ptr, char *filename);

/*
**	Retrieve the color of texture using texture coordinates <u> and <v>
*/
t_rgb	get_uv_color_at(t_buffer *buf, t_real u, t_real v);

# endif
#endif
