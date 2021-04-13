/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   compare.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 13:45:43 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:54:44 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>
#include <alias.h>
#include <math.h>

t_bool	vec3_cmp(const t_vec3 one, const t_vec3 two)
{
	if (fabs(one.x - two.x) < M_EPSILON
		&& fabs(one.y - two.y) < M_EPSILON
		&& fabs(one.z - two.z) < M_EPSILON)
		return (true);
	return (false);
}

t_bool	vec3_cmp_s(const t_vec3 one, const t_real two)
{
	if (fabs(one.x - two) < M_EPSILON
		&& fabs(one.y - two) < M_EPSILON
		&& fabs(one.z - two) < M_EPSILON)
		return (true);
	return (false);
}
