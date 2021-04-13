/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   magnitude.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:16:25 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:54:38 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>
#include <math.h>

t_real	vec3_mag(const t_vec3 vec)
{
	return (sqrt((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z)));
}
