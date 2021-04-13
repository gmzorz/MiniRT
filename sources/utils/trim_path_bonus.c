/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   trim_path_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/22 16:21:21 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:57:18 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <libft.h>
# include <parse.h>

char	*trim_path(char **line)
{
	char		*ret;
	int			size;
	int			idx;

	if (**line == '\"')
	{
		*line += 1;
		size = ft_strcspn(*line, DELIM_QUOT);
	}
	else
		size = ft_strcspn(*line, DELIM_SPACE);
	ret = (char *)ft_calloc(1, size + 1);
	idx = 0;
	while (idx < size)
	{
		ret[idx] = **line;
		idx += 1;
		*line += 1;
	}
	if (**line == '\"')
		*line += 1;
	return (ret);
}

#endif
