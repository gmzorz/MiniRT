/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zero.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/15 16:05:09 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:55:04 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

t_vec3	vec3_zero(void)
{
	const t_vec3	zeroed = (t_vec3){0.0, 0.0, 0.0};

	return (zeroed);
}
