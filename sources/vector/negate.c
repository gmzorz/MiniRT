/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   negate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/19 14:38:36 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 23:11:08 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

t_vec3	vec3_negate(const t_vec3 in)
{
	return ((t_vec3){-in.x, -in.y, -in.z});
}
