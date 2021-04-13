/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   translate_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/22 15:40:51 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 17:47:36 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>

t_bool	translate(t_scene *scene, t_vec3 *vec)
{
	const t_vec3	identity = (t_vec3){SHAPE_MOVE, SHAPE_MOVE, SHAPE_MOVE};
	t_vec3			fixed_dir;

	fixed_dir = vec3_mult(identity, scene->selection_axis);
	*vec = vec3_add(*vec, fixed_dir);
	return (true);
}
