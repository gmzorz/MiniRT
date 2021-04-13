/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_unused.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/11 15:49:18 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:41:29 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <error.h>

t_bool	parse_eol(char **line)
{
	int		len;

	len = ft_strspn(*line, DELIM_SPACE);
	if (len == 0 || **line == '\0')
		return (true);
	*line += len;
	if (**line == '\0')
		return (true);
	return (error_msg(ERR_UNUSED_PARAM));
}

t_bool	parse_unused(char **line)
{
	if (ft_strchr(DELIM_SPACE, **line))
		return (true);
	return (error_msg(ERR_UNUSED_PARAM));
}
