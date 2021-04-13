/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_and_exit_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/10 10:52:51 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/13 11:45:52 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <minirt.h>
# include <stdlib.h>

t_bool	free_and_exit(t_scene *scene)
{
	destroy_mlx(scene);
	free_cameras(&scene->cameras);
	free_shapes(&scene->shapes);
	free_lights(&scene->lights);
	free_textures(scene, &scene->textures);
	free_scene(scene);
	console_put(RT_EXIT);
	exit (1);
	return (true);
}

#endif
