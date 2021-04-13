/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_square.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/11 16:21:48 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:42:16 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <error.h>
#include <libft.h>

t_bool	parse_square(t_scene *scene, char **line)
{
	t_square	*square;
	t_material	mat;

	square = (t_square *)ft_calloc(1, sizeof(t_square));
	if (square == NULL)
		return (error_msg(ERR_ALLOC_SQUARE));
	if (!parse_vector(line, &square->origin)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_normal(line, &square->normal)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_real(line, &square->size)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_material(scene, line, &mat)
		|| !parse_eol(line))
		return (parse_failure(square));
	return (shape_push_back(&scene->shapes, square, mat, sh_square));
}
