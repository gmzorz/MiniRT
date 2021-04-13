/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_pyramid_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/19 16:27:54 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:42:03 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <parse.h>
#include <math.h>
#include <error.h>

t_bool	parse_pyramid(t_scene *scene, char **line)
{
	t_pyramid	*pyr;
	t_material	mat;

	pyr = (t_pyramid *)ft_calloc(1, sizeof(t_pyramid));
	if (pyr == NULL)
		return (error_msg(ERR_ALLOC_PYRAMID));
	if (!parse_vector(line, &pyr->origin)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_normal(line, &pyr->normal)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_real(line, &pyr->base_size)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_real(line, &pyr->height)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_material(scene, line, &mat)
		|| !parse_eol(line))
		return (parse_failure(pyr));
	pyr->base_size = fabs(pyr->base_size);
	return (shape_push_back(&scene->shapes, pyr, mat, sh_pyramid));
}
