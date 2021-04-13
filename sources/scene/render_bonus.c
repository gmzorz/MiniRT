/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/13 11:40:23 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:47:14 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <init.h>
# include <minirt.h>
# include <utils.h>

static void	fill_scaled_area(t_scene *scene, t_rgb color)
{
	int	u;
	int	v;

	u = 0;
	v = 0;
	while (u < scene->viewport_scale && u + scene->u < scene->main.width)
	{
		while (v < scene->viewport_scale && v + scene->v < scene->main.height)
		{
			write_color_at(&scene->main, u + scene->u, v + scene->v, color);
			v += 1;
		}
		v = 0;
		u += 1;
	}
}

static t_bool	render_scaled(t_scene *scene)
{
	t_rgb	color;
	t_ray	ray;

	while (scene->u < scene->main.width)
	{
		while (scene->v < scene->main.height)
		{
			camera_ray_init(scene, &ray, scene->u, scene->v);
			trace(scene, ray, &color);
			fill_scaled_area(scene, color);
			scene->v += scene->viewport_scale;
		}
		scene->v = 0;
		scene->u += scene->viewport_scale;
	}
	return (true);
}

t_bool	render(t_scene *scene)
{
	t_rgb	color;
	t_ray	ray;

	scene->u = 0;
	scene->v = 0;
	scene->completion = 0;
	if (scene->viewport != brdf && scene->viewport != shaded
		&& scene->viewport_scale > 1)
		return (render_scaled(scene));
	while (scene->u < scene->main.width)
	{
		while (scene->v < scene->main.height)
		{
			camera_ray_init(scene, &ray, scene->u, scene->v);
			trace(scene, ray, &color);
			write_color_at(&scene->main, scene->u, scene->v, color);
			scene->v += 1;
		}
		if (scene->viewport == shaded || scene->viewport == brdf)
			scene_completion(&scene->completion, scene->prog_add);
		scene->v = 0;
		scene->u += 1;
	}
	return (true);
}

#endif
