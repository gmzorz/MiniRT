/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mat4_add_vec.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/02 15:57:04 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:06:22 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>

t_mat4	mat4_add_vec(t_mat4 matrix, t_vec3 add)
{
	matrix.data[3][0] += add.x;
	matrix.data[3][1] += add.y;
	matrix.data[3][2] += add.z;
	return (matrix);
}
