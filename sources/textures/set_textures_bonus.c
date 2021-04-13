/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_textures_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/25 15:49:20 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:18:08 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <scene.h>
# include <utils.h>

void	set_textures(t_hitrecord *rec, t_bool brdf)
{
	t_real		u;
	t_real		v;

	u = set_tiling(rec->tex.u, rec->ref->mat.tex_size_x);
	v = set_tiling(rec->tex.v, rec->ref->mat.tex_size_y);
	set_diffuse(rec, u, v);
	set_normals(rec, u, v);
	if (brdf)
		set_roughness(rec, u, v);
	else
		set_gloss(rec, u, v);
	set_specularity(rec, u, v);
	set_reflection(rec, u, v);
	set_emission(rec, u, v);
}

#endif
