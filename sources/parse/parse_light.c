/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_light.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/11 14:40:20 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:41:58 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <error.h>
#include <libft.h>
#include <parse.h>

t_bool	parse_light(t_scene *scene, char **line)
{
	t_lights	*light;

	light = (t_lights *)ft_calloc(1, sizeof(t_lights));
	if (light == NULL)
		return (error_msg(ERR_ALLOC_LIGHT));
	if (!parse_vector(line, &light->origin)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_unit(line, &light->intensity, false)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_color(line, &light->color)
		|| !parse_eol(line))
		return (parse_failure(light));
	light->color = vec3_mult_s(light->color, light->intensity);
	return (light_push_back(&scene->lights, light));
}
