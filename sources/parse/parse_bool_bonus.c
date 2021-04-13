/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_bool_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/02 14:59:09 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:46:02 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <error.h>

t_bool	parse_bool(char **line, t_bool *in)
{
	int	num;

	if (!parse_int(line, &num))
		return (false);
	if (num != 0 && num != 1)
		return (error_msg(ERR_TF_CONDITION));
	*in = (t_bool)num;
	return (true);
}
