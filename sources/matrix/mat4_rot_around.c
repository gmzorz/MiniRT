/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mat4_rot_around.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/15 12:29:30 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:06:22 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>

t_mat4	mat4_rota(t_mat4 src, t_vec3 point, t_vec3 angle)
{
	src = mat4_sub_vec(src, point);
	src = mat4_mult(src, mat4_rotate(angle));
	src = mat4_add_vec(src, point);
	return (src);
}
