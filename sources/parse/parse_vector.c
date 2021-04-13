/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_vector.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 14:35:30 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:40:55 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <error.h>

t_bool	parse_vector(char **line, t_vec3 *vector)
{
	if (!parse_real(line, &vector->x)
		|| !parse_skip(line, ",", 1)
		|| !parse_real(line, &vector->y)
		|| !parse_skip(line, ",", 1)
		|| !parse_real(line, &vector->z)
		|| !parse_unused(line))
		return (error_msg(ERR_VEC_FAILURE));
	return (true);
}
