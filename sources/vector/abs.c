/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   abs.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/17 16:39:10 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 23:06:42 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>
#include <math.h>

t_vec3	vec3_abs(const t_vec3 vector)
{
	return ((t_vec3){fabs(vector.x), fabs(vector.y), fabs(vector.z)});
}
