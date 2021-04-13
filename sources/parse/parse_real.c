/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_real.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 14:50:33 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 17:27:38 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <error.h>
#include <utils.h>

/*
**	Check whether input string is consisting of one or more integers and
**	one or no precision delimiter
*/

static int	verify_double(const char *line)
{
	int			dot;
	t_bool		sign;
	int			idx;

	idx = 0;
	dot = 0;
	sign = false;
	while (line[idx] != '\0')
	{
		if (line[idx] == '-' && idx == 0 && !sign)
			sign = true;
		else if (line[idx] == '.')
			dot += 1;
		else if (!ft_isalnum(line[idx]))
			return (idx);
		if (dot > 1)
			return (0);
		idx += 1;
	}
	return (idx);
}

t_bool	parse_real(char **line, t_real *in)
{
	int			idx;
	int			len;
	char		*number;

	len = verify_double(*line);
	if (!len)
		return (error_msg(ERR_PAR_REAL));
	idx = 0;
	number = (char *)ft_calloc(1, len + 1);
	while (idx < len)
	{
		number[idx] = **line;
		*line += 1;
		idx += 1;
	}
	if (!ft_atof(number, in))
	{
		free(number);
		return (error_msg(ERR_PAR_REAL));
	}
	free(number);
	return (true);
}

t_bool	parse_unit(char **line, t_real *in, t_bool sign)
{
	t_real		min;

	min = setcnd(sign, -1.0, 0.0);
	if (!parse_real(line, in))
		return (false);
	if (*in > 1.0 || *in < min)
		return (error_msg(ERR_PAR_UNIT));
	return (true);
}
