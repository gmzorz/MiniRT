/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sub.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:15:12 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 23:11:21 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

t_vec3	vec3_sub(const t_vec3 one, const t_vec3 two)
{
	return ((t_vec3){one.x - two.x, one.y - two.y, one.z - two.z});
}

t_vec3	vec3_sub_s(const t_vec3 one, const t_real two)
{
	return ((t_vec3){one.x - two, one.y - two, one.z - two});
}
