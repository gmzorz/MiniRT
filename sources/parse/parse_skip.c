/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_skip.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/21 12:47:53 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:40:51 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <error.h>

t_bool	parse_skip(char **line, const char *delim, int skip_count)
{
	int		len;

	len = ft_strspn(*line, delim);
	if (!len)
		return (error_msg(ERR_PAR_DELIM));
	if (skip_count && len == skip_count)
		*line += skip_count;
	else
		*line += len;
	return (true);
}
