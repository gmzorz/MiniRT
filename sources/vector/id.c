/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   id.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/12 17:48:27 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 23:55:56 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

t_vec3	vec3_id(const int id)
{
	const t_vec3	identity[3] = {
		(t_vec3){1.0, 0.0, 0.0},
		(t_vec3){0.0, 1.0, 0.0},
		(t_vec3){0.0, 0.0, 1.0}
	};

	return (identity[id]);
}
