/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   aabb_init.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/14 15:07:06 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 17:56:46 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <shapes.h>

t_bool	volume_init(t_aabb *volume)
{
	const t_vec3	vec_max = (t_vec3){M_INFINITY, M_INFINITY, M_INFINITY};
	const t_vec3	vec_min = (t_vec3){-M_INFINITY, -M_INFINITY, -M_INFINITY};

	volume->using = true;
	volume->min = vec_max;
	volume->max = vec_min;
	return (true);
}
