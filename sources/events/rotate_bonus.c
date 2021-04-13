/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/22 16:36:37 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 17:47:02 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>

t_bool	rotate(t_scene *scene, t_mat4 *mat)
{
	const t_vec3	identity = (t_vec3){SHAPE_ROT, SHAPE_ROT, SHAPE_ROT};
	t_vec3			mult;

	mult = vec3_mult(identity, scene->selection_axis);
	*mat = mat4_mult(mat4_rotx(mult.x), *mat);
	*mat = mat4_mult(mat4_roty(mult.y), *mat);
	*mat = mat4_mult(mat4_rotz(mult.z), *mat);
	return (true);
}
