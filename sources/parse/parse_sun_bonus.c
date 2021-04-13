/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_sun_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/19 17:26:57 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:42:09 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <parse.h>
# include <error.h>
# include <math.h>

t_bool	parse_sun(t_scene *scene, char **line)
{
	if (scene->sun == true)
		return (error_msg(ERR_SUN_EXISTS));
	scene->sun = true;
	if (!parse_normal(line, &scene->sun_direction)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_real(line, &scene->sun_intensity)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_unit(line, &scene->sun_size, true)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_color(line, &scene->sun_color)
		|| !parse_eol(line))
		return (false);
	scene->sun_size = pow(2, (1 - fabs(scene->sun_size)) * 10);
	scene->sun_intensity = fabs(scene->sun_intensity);
	return (true);
}

#endif
