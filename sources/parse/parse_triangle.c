/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_triangle.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/11 16:55:27 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:42:25 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <error.h>
#include <libft.h>

t_bool	parse_triangle(t_scene *scene, char **line)
{
	t_triangle	*tri;
	t_material	mat;

	tri = (t_triangle *)ft_calloc(1, sizeof(t_triangle));
	if (tri == NULL)
		return (error_msg(ERR_ALLOC_TRIANGLE));
	if (!parse_vector(line, &tri->vert[0])
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_vector(line, &tri->vert[1])
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_vector(line, &tri->vert[2])
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_material(scene, line, &mat)
		|| !parse_eol(line))
		return (parse_failure(tri));
	return (shape_push_back(&scene->shapes, tri, mat, sh_triangle));
}
