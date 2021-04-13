/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sassaa_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/06 14:20:45 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/13 11:54:47 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <init.h>
# include <utils.h>
# include <math.h>
# include <filter.h>
# include <minirt.h>

/*
**	Sobel filter using 5x5 matrix instead of 3x3, more accurate
*/

static t_rgb	sobel(t_buffer *in, int u, int v)
{
	t_rgb		x;
	t_rgb		y;
	t_vec2		knl;
	int			lt[2];

	knl = (t_vec2){0.0, 0.0};
	x = vec3_zero();
	y = vec3_zero();
	while (knl.u <= 2)
	{
		while (knl.v <= 2)
		{
			lt[0] = clamp(knl.u + u, 0, in->width - 1);
			lt[1] = clamp(knl.v + v, 0, in->height - 1);
			x = vec3_add(x, vec3_mult_s(get_color_at(in, lt[0], lt[1]),
						sobel5x5(knl.u + 2, knl.v + 2, 1)));
			y = vec3_add(y, vec3_mult_s(get_color_at(in, lt[0], lt[1]),
						sobel5x5(knl.u + 2, knl.v + 2, 0)));
			knl.v += 1;
		}
		knl.v = -2;
		knl.u += 1;
	}
	return (sobel_sum3(x, y));
}

static t_rgb	ssaa_rand(t_scene *scene, int samples)
{
	t_rgb		total;
	t_rgb		traced;
	int			idx;
	t_ray		ray;

	idx = 0;
	total = get_color_at(&scene->main, scene->u, scene->v);
	while (idx < samples)
	{
		camera_ray_init(scene, &ray,
			scene->u + rt_rand(), scene->v + rt_rand());
		trace(scene, ray, &traced);
		total = vec3_add(total, traced);
		idx += 1;
	}
	return (vec3_div_s(total, samples + 1));
}

static void	sbl_make(t_scene *scene, t_buffer *save)
{
	int		scalar;
	t_real	sample_count;

	sample_count = clamp(fabs(greyscale(sobel(&scene->main,
						scene->u, scene->v))), 0.0, 1.0);
	scalar = (int)(scene->aa_samples * sample_count);
	if (scalar)
		write_color_at(save, scene->u, scene->v,
			ssaa_rand(scene, scalar));
}

t_bool	sassaa(t_scene *scene)
{
	t_buffer	save;

	if (!copy_buffer(&scene->main, scene->mlx.ptr, &save))
		return (false);
	scene->u = 0;
	scene->v = 0;
	console_put(RT_AA_PASS);
	scene->completion = 0;
	while (scene->u < scene->main.width)
	{
		while (scene->v < scene->main.height)
		{
			sbl_make(scene, &save);
			scene->v += 1;
		}
		scene_completion(&scene->completion, scene->prog_add);
		scene->v = 0;
		scene->u += 1;
	}
	copy_buffer(&save, NULL, &scene->main);
	destroy_buffer(&save, scene->mlx.ptr);
	return (true);
}

#endif
