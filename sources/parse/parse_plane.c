/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_plane.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/11 15:59:53 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:42:12 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <error.h>
#include <libft.h>

t_bool	parse_plane(t_scene *scene, char **line)
{
	t_plane		*plane;
	t_material	mat;

	plane = (t_plane *)ft_calloc(1, sizeof(t_plane));
	if (plane == NULL)
		return (error_msg(ERR_ALLOC_PLANE));
	if (!parse_vector(line, &plane->origin)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_normal(line, &plane->normal)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_material(scene, line, &mat)
		|| !parse_eol(line))
		return (parse_failure(plane));
	return (shape_push_back(&scene->shapes, plane, mat, sh_plane));
}
