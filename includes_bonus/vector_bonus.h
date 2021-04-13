/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_bonus.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/18 13:42:26 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/02 11:05:51 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_BONUS_H
# define VECTOR_BONUS_H
# include <vector.h>
# include <shapes_bonus.h>

typedef struct s_coords
{
	t_vec3		up;
	t_vec3		right;
	t_vec3		forward;
	t_vec3		origin;
}	t_coords;

/*
**	return a random vector pointing along the positive Y axis hemisphere
*/
t_vec3	vec3_hsphere(t_vec3 normal,
			const t_real rand1, const t_real rand2);

/*
**	Check whether vector is within volume bounds
*/
t_bool	vec3_is_bounds(const t_vec3 in, const t_aabb volume);

#endif
