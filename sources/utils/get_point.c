/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_point.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/16 14:30:05 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:15:37 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

t_vec3	get_point(t_vec3 ro, t_vec3 rd, t_real t)
{
	return (vec3_add(ro, vec3_mult_s(rd, t)));
}
