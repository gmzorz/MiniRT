/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:14:58 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 23:11:48 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

t_vec3	vec3_unit(const t_vec3 vec)
{
	t_real	mag;

	mag = vec3_mag(vec);
	return (vec3_div_s(vec, mag));
}
