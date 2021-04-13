/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   select_shape_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/12 14:45:06 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:46:26 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <init.h>
#include <minirt.h>
#include <events.h>

static void	print_selected_shape(t_shapetype type)
{
	if (type == sh_sphere)
		console_putstr(SH_SELECT, "sphere");
	if (type == sh_plane)
		console_putstr(SH_SELECT, "plane");
	if (type == sh_cylinder)
		console_putstr(SH_SELECT, "cylinder");
	if (type == sh_square)
		console_putstr(SH_SELECT, "square");
	if (type == sh_triangle)
		console_putstr(SH_SELECT, "triangle");
	if (type == sh_disk)
		console_putstr(SH_SELECT, "disk");
	if (type == sh_cube)
		console_putstr(SH_SELECT, "cube");
	if (type == sh_pyramid)
		console_putstr(SH_SELECT, "pyramid");
	if (type == sh_trimesh)
		console_putstr(SH_SELECT, "triangle mesh");
}

t_bool	select_shape(t_scene *scene)
{
	t_hitrecord		record;

	ft_memset(&record, 0, sizeof(t_hitrecord));
	camera_ray_init(scene, &record.ray, scene->u, scene->v);
	record.distance = M_INFINITY;
	if (intersect(scene->shapes, &record) && record.ref)
	{
		set_textures(&record, false);
		if (scene->selection_mode == SELECTION_UNDEFINED)
			scene->selection_mode = SELECTION_TRANSLATE;
		scene->selected_shape = record.ref;
		scene->do_update = true;
		print_selected_shape(record.ref->type);
		return (true);
	}
	else
		scene->selected_shape = NULL;
	return (false);
}
