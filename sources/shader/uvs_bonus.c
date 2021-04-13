/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   uvs_bonus.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/13 14:38:01 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:21:32 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <scene.h>
# include <utils.h>

t_rgb	s_uvs(t_scene *scene, t_hitrecord *rec)
{
	t_rgb	col;
	t_real	u;
	t_real	v;

	(void)scene;
	u = set_tiling(rec->tex.u, rec->ref->mat.tex_size_x);
	v = set_tiling(rec->tex.v, rec->ref->mat.tex_size_y);
	col.x = u;
	col.y = v;
	col.z = 1 - col.x - col.y;
	return (vec3_clamp(col, 0, 1));
}

#endif
