/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:14:55 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 23:07:11 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

t_vec3	vec3_add(const t_vec3 one, const t_vec3 two)
{
	return ((t_vec3){one.x + two.x, one.y + two.y, one.z + two.z});
}

t_vec3	vec3_add_s(const t_vec3 one, const t_real two)
{
	return ((t_vec3){one.x + two, one.y + two, one.z + two});
}
