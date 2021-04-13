/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   brdf_render_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/01 16:04:01 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/13 00:14:26 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <init.h>
#include <utils.h>
#include <math.h>
#include <minirt.h>
#include <events.h>

static void	brdf_write_color(t_scene *scene, t_rgb *color, t_vec2 frag)
{
	t_real		scale;

	scale = 1.0 / (t_real)(scene->brdf_spp * 4);
	*color = vec3_mult_s(*color, scale);
	color->x = pow(color->x, 0.4545454545);
	color->y = pow(color->y, 0.4545454545);
	color->z = pow(color->z, 0.4545454545);
	write_color_at(&scene->main, (int)frag.u, (int)frag.v, *color);
	*color = vec3_zero();
}

void	compute_pixel(t_scene *scene, t_vec2 frag)
{
	t_ray			ray;
	t_rgb			color;
	int				idx[2];
	static t_vec2	offset[4] = {
		{-0.25, -0.25}, {-0.25, 0.25}, {0.25, -0.25}, {0.25, 0.25}};

	idx[0] = 0;
	color = vec3_zero();
	while (idx[0] < scene->brdf_spp)
	{
		idx[1] = 0;
		while (idx[1] < 4)
		{
			camera_ray_init(scene, &ray,
				frag.u + offset[idx[1]].u,
				frag.v + offset[idx[1]].v);
			color = vec3_add(color, brdf_trace(scene, ray,
						scene->brdf_depth));
			idx[1] += 1;
		}
		idx[0] += 1;
	}
	brdf_write_color(scene, &color, frag);
}

t_bool	brdf_render(t_scene *scene)
{
	t_rgb	color;
	t_vec2	frag;

	if (scene->brdf_threading)
		return (brdf_threading(scene));
	color = vec3_zero();
	frag = (t_vec2){0.0, 0.0};
	console_put(RT_RENDER);
	scene->completion = 0;
	while (frag.u < scene->main.width)
	{
		while (frag.v < scene->main.height)
		{
			compute_pixel(scene, frag);
			frag.v += 1;
		}
		scene_completion(&scene->completion, scene->prog_add);
		frag.v = 0;
		frag.u += 1;
	}
	if (scene->brdf_save)
		take_screenshot(scene);
	return (true);
}
