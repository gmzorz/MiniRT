/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scene_init_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 16:08:58 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:30:25 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <minirt.h>
# include <parse.h>
# include <utils.h>
# include <init.h>

t_bool	scene_init(t_scene *scene, char *rt_file)
{
	console_put(SCENE_INIT);
	rand_init();
	scene->mlx.ptr = mlx_init();
	scene->viewport = flat;
	scene->viewport_scale = 2;
	scene->ambience = -1;
	scene->cam_idx = 1;
	scene->do_update = true;
	if (!parse_to_scene(scene, rt_file))
		return (false);
	return (scene_verify(scene));
}

#endif
