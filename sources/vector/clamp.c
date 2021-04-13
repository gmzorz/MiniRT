/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clamp.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 15:20:39 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 23:20:21 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>
#include <utils.h>

t_vec3	vec3_clamp(t_vec3 in, const t_real min, const t_real max)
{
	in.x = clamp(in.x, min, max);
	in.y = clamp(in.y, min, max);
	in.z = clamp(in.z, min, max);
	return (in);
}
