/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   greater.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/10 15:12:23 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:54:48 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

t_bool	vec3_grt(const t_vec3 vector, const t_real number)
{
	if (vector.x > number || vector.y > number || vector.z > number)
		return (true);
	return (false);
}
