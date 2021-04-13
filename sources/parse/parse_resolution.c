/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_resolution.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 14:22:32 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:41:33 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <error.h>
#include <parse.h>
#include <utils.h>

t_bool	parse_resolution(t_scene *scene, char **line)
{
	int	max_size[2];

	if (scene->mlx.width && scene->mlx.height)
		return (error_msg(ERR_RES_EXISTS));
	if (!parse_int(line, &scene->mlx.width)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_int(line, &scene->mlx.height)
		|| !parse_eol(line))
		return (false);
	if (scene->mlx.width <= 0 || scene->mlx.height <= 0)
		return (error_msg(ERR_RES_NEG));
	mlx_get_screen_size(scene->mlx.ptr, &max_size[0], &max_size[1]);
	if (scene->mlx.width > max_size[0] || scene->mlx.height > max_size[1])
		warning_msg(WARN_RES_MAX_RES);
	scene->mlx.width = (int)clamp(scene->mlx.width, 0, max_size[0]);
	scene->mlx.height = (int)clamp(scene->mlx.height, 0, max_size[1]);
	scene->ratio = (t_real)scene->mlx.width / (t_real)scene->mlx.height;
	scene->prog_add = 50.0 / scene->mlx.width;
	return (true);
}
