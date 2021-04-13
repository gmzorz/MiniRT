/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   buffer_init.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 16:45:47 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:38:26 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 0
# include <minirt.h>
# include <unistd.h>

t_bool	buffer_init(t_scene *scene)
{
	console_put(WIN_INIT);
	scene->mlx.win = mlx_new_window(scene->mlx.ptr, scene->mlx.width,
			scene->mlx.height, RT_TITLE);
	console_put(BUF_INIT);
	if (!new_buffer(&scene->main, scene->mlx.ptr,
			scene->mlx.width, scene->mlx.height))
		return (false);
	if (scene->mlx.win == NULL)
		return (false);
	return (true);
}

#endif
