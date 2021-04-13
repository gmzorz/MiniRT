/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cross.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:15:25 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 23:16:31 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

t_vec3	vec3_cross(const t_vec3 right, const t_vec3 forward)
{
	return ((t_vec3){
		right.y * forward.z - right.z * forward.y,
		right.z * forward.x - right.x * forward.z,
		right.x * forward.y - right.y * forward.x});
}
