/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pyramid_intersect_bonus.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/19 16:58:12 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:33:21 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>

t_bool	pyramid_intersect(t_shapes *catch, t_hitrecord *rec)
{
	t_pyramid	*pyr;
	t_shapes	square;
	t_shapes	face;
	t_bool		hit;
	int			idx;

	pyr = catch->shape;
	square.shape = (t_square *)&pyr->base;
	if (square_intersect(&square, rec))
	{
		hit = true;
		rec->ref = catch;
	}
	idx = 0;
	while (idx < 4)
	{
		face.shape = (t_triangle *)&pyr->face[idx];
		if (triangle_intersect(&face, rec))
		{
			hit = true;
			rec->ref = catch;
		}
		idx += 1;
	}
	return (hit);
}
