/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_textures_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/01 13:02:25 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:33:43 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <stdlib.h>

void	free_textures(t_scene *scene, t_texture **list)
{
	t_texture	*start;
	t_texture	*next;

	console_put(RT_FREE_TEXTURES);
	start = *list;
	while (start)
	{
		next = start->next;
		free(start->file);
		mlx_destroy_image(scene->mlx.ptr, start->map->image);
		free(start->map);
		free(start);
		start = next;
	}
	*list = NULL;
}
