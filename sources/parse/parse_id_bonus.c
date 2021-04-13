/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_id_bonus.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/21 14:55:39 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:38:04 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <libft.h>
# include <parse.h>

/*
**	parse ID and return, to compare
**	also, comments!
*/

char	*parse_id(char **line)
{
	char	*id;
	int		len;
	int		idx;

	idx = 0;
	*line += ft_strspn(*line, DELIM_SPACE);
	if (**line == '\0' || **line == '#')
		return (NULL);
	len = ft_strcspn(*line, DELIM_SPACE);
	if (len == 0)
		return (NULL);
	id = (char *)ft_calloc(1, len + 1);
	ft_memcpy(id, *line, len);
	*line += len;
	*line += ft_strspn(*line, DELIM_SPACE);
	return (id);
}

#endif
