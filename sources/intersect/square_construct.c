/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   square_construct.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/29 17:13:12 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:52:26 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <scene.h>
#include <init.h>

t_bool	square_construct(t_shapes *catch)
{
	t_square	*sq;
	t_vec3		corners[4];
	t_real		half;

	sq = catch->shape;
	sq->size = fabs(sq->size);
	if (vec3_cmp_s(sq->span_a, 0.0))
		vec3_local_coords(sq->normal, &sq->span_a, &sq->span_b);
	half = sq->size / 2;
	corners[0] = vec3_add(sq->origin, vec3_mult_s(sq->span_a, half));
	corners[1] = vec3_add(corners[0], vec3_mult_s(sq->span_b, half));
	corners[0] = vec3_sub(corners[0], vec3_mult_s(sq->span_b, half));
	corners[2] = vec3_sub(sq->origin, vec3_mult_s(sq->span_a, half));
	corners[3] = vec3_add(corners[2], vec3_mult_s(sq->span_b, half));
	corners[2] = vec3_sub(corners[2], vec3_mult_s(sq->span_b, half));
	volume_init(&catch->volume);
	volume_add_vec(&catch->volume, corners[0]);
	volume_add_vec(&catch->volume, corners[1]);
	volume_add_vec(&catch->volume, corners[2]);
	volume_add_vec(&catch->volume, corners[3]);
	return (true);
}
