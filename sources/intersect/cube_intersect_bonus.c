/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cube_intersect_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/18 15:39:30 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:31:51 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <scene.h>

t_bool	cube_intersect(t_shapes *catch, t_hitrecord *rec)
{
	t_shapes	face;
	t_cube		*cube;
	int			idx;
	t_bool		hit;

	idx = 0;
	cube = catch->shape;
	hit = false;
	while (idx < 6)
	{
		face.shape = (t_square *)&cube->face[idx];
		if (square_intersect(&face, rec))
		{
			hit = true;
			rec->ref = catch;
		}
		idx += 1;
	}
	return (hit);
}

#endif
