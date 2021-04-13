/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   construct.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/15 14:21:37 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:13:05 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 0
# include <jump_tables.h>
# include <unistd.h>

t_bool	jump_construct(t_shapes *shape)
{
	int						idx;
	static t_jump_construct	cs[] = {
		{sh_sphere, sphere_construct},
		{sh_plane, plane_construct},
		{sh_square, square_construct},
		{sh_cylinder, cylinder_construct},
		{sh_triangle, triangle_construct},
		{sh_noshape, NULL}	
	};

	idx = 0;
	if (shape->construct == false)
		return (true);
	while (cs[idx].type != sh_noshape && shape->type != cs[idx].type)
		idx += 1;
	if (shape->type == cs[idx].type)
	{
		cs[idx].construct(shape);
		shape->construct = false;
		return (true);
	}
	return (false);
}

#endif
