/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shader.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 16:28:56 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:12:49 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 0
# include <jump_tables.h>
# include <unistd.h>

t_bool	jump_shader(t_scene *scene, t_hitrecord *rec, t_rgb *col)
{
	int						idx;
	static t_jump_shader	js[] = {
		{flat, s_flat},
		{unlit, s_unlit},
		{shaded, s_shaded},
		{aabb, s_aabb},
		{none, NULL}
	};

	idx = 0;
	while (js[idx].mode != none && scene->viewport != js[idx].mode)
		idx += 1;
	if (scene->viewport == js[idx].mode)
		*col = js[idx].shader(scene, rec);
	return (true);
}

#endif
