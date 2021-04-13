/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   local_coords.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/18 14:24:14 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 23:20:37 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>
#include <math.h>
#include <unistd.h>

/*
**	Alternative to performing the cross product twice to create a
**	local coordinate system, does not involve as many calculations.
*/

void	vec3_local_coords(const t_vec3 up, t_vec3 *fw, t_vec3 *rt)
{
	if (fabs(up.x) > fabs(up.y))
		*fw = vec3_div_s((t_vec3){up.z, 0, -up.x},
				sqrt(up.x * up.x + up.z * up.z));
	else
		*fw = vec3_div_s((t_vec3){0, -up.z, up.y},
				sqrt(up.y * up.y + up.z * up.z));
	if (rt == NULL)
		return ;
	*rt = vec3_cross(up, *fw);
}
