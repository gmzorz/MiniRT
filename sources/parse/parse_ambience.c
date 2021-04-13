/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_ambience.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 13:43:24 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:41:38 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <error.h>
#include <parse.h>

t_bool	parse_ambience(t_scene *scene, char **line)
{
	if (scene->ambience != -1)
		return (error_msg(ERR_AMB_EXISTS));
	if (!parse_unit(line, &scene->ambience, false)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_color(line, &scene->ambient_color)
		|| !parse_eol(line))
		return (false);
	scene->ambient_color = vec3_mult_s(scene->ambient_color, scene->ambience);
	return (true);
}
