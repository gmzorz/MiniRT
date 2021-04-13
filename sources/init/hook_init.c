/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook_init.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/10 10:34:47 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:38:31 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 0
# include <mlx.h>
# include <events.h>
# include <minirt.h>

t_bool	hook_init(t_scene *scene)
{
	console_put(MLX_INIT);
	mlx_hook(scene->mlx.win, EXIT_WINDOW, MASK_BUTTON, close_program, scene);
	mlx_hook(scene->mlx.win, KEY_DOWN, MASK_BUTTON, key_handle, scene);
	console_put(RT_READY);
	mlx_loop(scene->mlx.ptr);
	return (true);
}

#endif
