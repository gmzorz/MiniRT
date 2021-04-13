/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scene_init.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 16:08:58 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/13 12:43:21 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <parse.h>
#include <libft.h>
#include <error.h>

t_bool	scene_verify(t_scene *scene)
{
	if (!scene->mlx.width && !scene->mlx.height)
		return (error_msg(ERR_UNDEF_RES));
	if (scene->cameras == NULL)
		return (error_msg(ERR_UNDEF_CAM));
	return (true);
}

t_scene	*scene_allocate(void)
{
	t_scene	*scene;

	scene = (t_scene *)ft_calloc(1, sizeof(t_scene));
	return (scene);
}

#if IS_BONUS == 0

t_bool	scene_init(t_scene *scene, char *rt_file)
{
	console_put(SCENE_INIT);
	scene->mlx.ptr = mlx_init();
	scene->viewport = flat;
	scene->ambience = -1;
	scene->cam_idx = 1;
	if (!parse_to_scene(scene, rt_file))
		return (false);
	return (scene_verify(scene));
}

#endif
