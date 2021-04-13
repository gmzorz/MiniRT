/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   destroy_mlx_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/11 13:56:26 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:33:52 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <minirt.h>

void	destroy_mlx(t_scene *scene)
{
	console_put(RT_DESTROY);
	if (scene->main.image)
		mlx_destroy_image(scene->mlx.ptr, scene->main.image);
	if (scene->selection.image)
		mlx_destroy_image(scene->mlx.ptr, scene->selection.image);
	if (scene->mlx.win)
		mlx_destroy_window(scene->mlx.ptr, scene->mlx.win);
}

#endif
