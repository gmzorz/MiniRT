/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_int.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 14:29:37 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:41:22 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <error.h>

/*
**	Check whether input string is consisting of one or more integers
*/

static int	verify_int(char *line)
{
	int			idx;
	t_bool		sign;

	idx = 0;
	sign = false;
	while (line[idx] != '\0')
	{
		if (line[idx] == '-' && idx == 0 && !sign)
			sign = true;
		else if (!ft_isdigit(line[idx]))
			return (idx);
		idx += 1;
	}
	return (idx);
}

t_bool	parse_int(char **line, int *in)
{
	char		*number;
	int			len;
	int			idx;

	len = verify_int(*line);
	if (len == 0)
		return (error_msg(ERR_PAR_INT));
	idx = 0;
	number = (char *)ft_calloc(1, len + 1);
	while (idx < len)
	{
		number[idx] = **line;
		*line += 1;
		idx += 1;
	}
	if (!ft_atoi(number, in))
	{
		free(number);
		return (error_msg(ERR_PAR_INT));
	}
	free(number);
	return (true);
}
