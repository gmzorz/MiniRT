/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   average.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/10 15:01:05 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:56:06 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

t_vec3	vec3_avg(const t_vec3 one, const t_vec3 two)
{
	return (vec3_mult_s(vec3_add(one, two), 0.5));
}
