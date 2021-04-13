/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_normal.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/10 15:09:03 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:41:00 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <error.h>

t_bool	parse_normal(char **line, t_vec3 *normal)
{
	if (!parse_vector(line, normal))
		return (false);
	if (vec3_grt(*normal, 1.0) || vec3_lss(*normal, -1.0))
		return (error_msg(ERR_INVALID_NORMAL));
	if (vec3_cmp(*normal, vec3_zero()))
		return (error_msg(ERR_ZERO_NORMAL));
	*normal = vec3_unit(*normal);
	return (true);
}
