/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 16:50:53 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/13 12:10:59 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 0
# include <scene.h>

t_bool	update(t_scene *scene)
{
	construct(&scene->shapes);
	render(scene);
	mlx_put_image_to_window(scene->mlx.ptr,
		scene->mlx.win, scene->main.image, 0, 0);
	return (true);
}

#endif
