/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dot.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:15:03 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:54:29 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

t_real	vec3_dot(const t_vec3 one, const t_vec3 two)
{
	return (one.x * two.x + one.y * two.y + one.z * two.z);
}
