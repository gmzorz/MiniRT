/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mat4_mult_dir.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/01 14:44:46 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:06:22 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>

/*
**	This can be used to generate a direction for a dynamic camera
**	Meaning we can update our camera and apply translation.
*/

t_vec3	mat4_mult_dir(t_mat4 matrix, t_vec3 dir)
{
	t_vec3	new;

	new.x = dir.x * matrix.data[0][0] + dir.y
		* matrix.data[1][0] + dir.z * matrix.data[2][0];
	new.y = dir.x * matrix.data[0][1] + dir.y
		* matrix.data[1][1] + dir.z * matrix.data[2][1];
	new.z = dir.x * matrix.data[0][2] + dir.y
		* matrix.data[1][2] + dir.z * matrix.data[2][2];
	return (new);
}
