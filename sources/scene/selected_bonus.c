/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   selected_bonus.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/12 16:31:00 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/13 13:15:24 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <scene.h>
# include <filter.h>
# include <init.h>
# include <libft.h>

static t_bool	draw_shape_outline(t_scene *scene)
{
	const t_rgb		hitcol = (t_vec3){1.0, 1.0, 1.0};
	t_hitrecord		rec;
	t_rgb			col;
	t_shapes		its;

	ft_memset(&rec, 0, sizeof(t_hitrecord));
	camera_ray_init(scene, &rec.ray, scene->u, scene->v);
	rec.distance = M_INFINITY;
	col = vec3_zero();
	its.shape = scene->selected_shape->shape;
	its.type = scene->selected_shape->type;
	its.volume = scene->selected_shape->volume;
	its.next = NULL;
	if (intersect(&its, &rec))
		col = hitcol;
	write_color_at(&scene->selection, scene->u, scene->v, col);
	rec.ref = NULL;
	return (true);
}

t_rgb	edge_color(const int selection_mode)
{
	const t_rgb	edge[2] = {
		(t_rgb){0.2, 1.0, 0.2},
		(t_rgb){1.0, 0.2, 0.2}};

	return (edge[selection_mode]);
}

t_bool	set_selection(t_scene *scene)
{
	const t_rgb	edge[2] = {
		(t_rgb){0.2, 1.0, 0.2},
		(t_rgb){1.0, 0.2, 0.2}};

	if (scene->selected_shape == NULL || scene->viewport == brdf
		|| scene->viewport == shaded)
	{
		scene->do_update = false;
		return (true);
	}
	scene->u = 0;
	scene->v = 0;
	while (scene->u < scene->main.width)
	{
		while (scene->v < scene->main.height)
		{
			draw_shape_outline(scene);
			scene->v += 1;
		}
		scene->v = 0;
		scene->u += 1;
	}
	return (f_sobel(&scene->selection, &scene->main,
			edge[scene->selection_mode]));
}

#endif
