/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reflect.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/27 14:12:47 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:56:00 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

t_vec3	vec3_reflect(const t_vec3 vec, const t_vec3 normal)
{
	t_vec3	rfl;

	rfl = vec3_mult_s(vec3_mult_s(normal, 2), vec3_dot(vec, normal));
	return (vec3_unit(vec3_sub(vec, rfl)));
}

t_vec3	vec3_bounce(const t_vec3 vec, const t_vec3 normal)
{
	return (vec3_negate(vec3_reflect(vec, normal)));
}
