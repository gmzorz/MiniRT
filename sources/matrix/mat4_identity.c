/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mat4_identity.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/01 11:28:54 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 23:19:29 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>

/*
**	General identity matrix
**	normalized for translation
*/

t_mat4	mat4_identity(void)
{
	t_vec3	right;
	t_vec3	up;
	t_vec3	forward;
	t_vec3	zeroed;

	right = vec3_id(ID_X);
	up = vec3_id(ID_Y);
	forward = vec3_id(ID_Z);
	zeroed = vec3_zero();
	return (mat4(zeroed, forward, right, up));
}
