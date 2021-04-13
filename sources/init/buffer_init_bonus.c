/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   buffer_init_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 16:45:47 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:29:08 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <minirt.h>

t_bool	buffer_init(t_scene *scene)
{
	console_put(WIN_INIT);
	scene->mlx.win = mlx_new_window(scene->mlx.ptr, scene->mlx.width,
			scene->mlx.height, RT_TITLE);
	console_put(BUF_INIT);
	if (!new_buffer(&scene->main, scene->mlx.ptr,
			scene->mlx.width, scene->mlx.height))
		return (false);
	if (!new_buffer(&scene->selection, scene->mlx.ptr,
			scene->mlx.width, scene->mlx.height))
		return (false);
	if (scene->mlx.win == NULL)
		return (false);
	return (true);
}

#endif
