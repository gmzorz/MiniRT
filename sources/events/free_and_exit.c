/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_and_exit.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/10 10:52:51 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:39:33 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 0
# include <minirt.h>
# include <stdlib.h>

t_bool	free_and_exit(t_scene *scene)
{
	destroy_mlx(scene);
	free_cameras(&scene->cameras);
	free_shapes(&scene->shapes);
	free_lights(&scene->lights);
	free_scene(scene);
	console_put(RT_EXIT);
	exit (1);
	return (true);
}

#endif
