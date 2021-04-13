/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   skybox_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/01 15:19:18 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 22:57:49 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <scene.h>
# include <math.h>
# include <buffer_bonus.h>

/*
**	Similar effect to the "spot" cosine specular highlights. instead we project
**	this on the sky
*/

static t_rgb	set_sun(const t_scene *scene, const t_vec3 rd, const t_bool env)
{
	t_vec3	col;
	t_real	cosine;

	cosine = vec3_dot(rd, scene->sun_direction);
	if (cosine < 0)
		return (vec3_zero());
	col = vec3_mult_s(scene->sun_color, pow(cosine, scene->sun_size));
	col = vec3_clamp(col, 0.0, 1.0);
	if (env)
		return (vec3_mult_s(col, scene->sun_intensity));
	return (col);
}

t_rgb	set_skybox(const t_scene *scene, const t_vec3 rd, const t_bool env)
{
	t_vec3		rd_inverse;
	t_real		u;
	t_real		v;
	t_rgb		col;

	col = vec3_zero();
	rd_inverse = (t_vec3){-rd.x, rd.y, -rd.z};
	if (scene->skybox.t_diffuse.map)
	{
		u = 0.5 + atan2(rd_inverse.z, rd_inverse.x) / PI_2;
		v = 0.5 - asin(rd_inverse.y) / M_PI;
		col = get_uv_color_at(scene->skybox.t_diffuse.map, u, v);
		if (env)
			col = vec3_mult(col, scene->skybox.emission);
	}
	if (scene->sun)
		col = vec3_add(col, set_sun(scene, rd_inverse, env));
	if (!env)
		col = vec3_clamp(col, 0.0, 1.0);
	return (col);
}

#endif
