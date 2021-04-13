/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/13 11:40:23 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:42:39 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 0
# include <init.h>
# include <minirt.h>
# include <utils.h>

t_bool	render(t_scene *scene)
{
	t_rgb	color;
	t_ray	ray;

	scene->u = 0;
	scene->v = 0;
	scene->completion = 0;
	while (scene->u < scene->main.width)
	{
		while (scene->v < scene->main.height)
		{
			camera_ray_init(scene, &ray, scene->u, scene->v);
			trace(scene, ray, &color);
			write_color_at(&scene->main, scene->u, scene->v, color);
			scene->v += 1;
		}
		if (scene->viewport == shaded)
			scene_completion(&scene->completion, scene->prog_add);
		scene->v = 0;
		scene->u += 1;
	}
	return (true);
}

#endif
