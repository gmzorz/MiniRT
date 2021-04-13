/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/15 14:21:37 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:12:23 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 0
# include <jump_tables.h>
# include <unistd.h>

t_bool	jump_intersect(t_shapes *shape, t_hitrecord *rec)
{
	int						idx;
	static t_jump_intersect	is[] = {
		{sh_sphere, sphere_intersect},
		{sh_plane, plane_intersect},
		{sh_square, square_intersect},
		{sh_cylinder, cylinder_intersect},
		{sh_triangle, triangle_intersect},
		{sh_noshape, NULL}	
	};

	idx = 0;
	while (is[idx].type != sh_noshape && shape->type != is[idx].type)
		idx += 1;
	if (shape->type == is[idx].type)
		return (is[idx].intersect(shape, rec));
	return (false);
}

#endif
