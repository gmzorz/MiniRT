/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_match.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/14 12:59:25 by goosterl      #+#    #+#                 */
/*   Updated: 2021/03/26 16:33:57 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	ft_match:
**	returns 1 if <ident> matches <match>
**	returns 0 if fails
**
**	ft_matchend:
**	returns 1 if <match> matches ending chars of <ident>
**	returns 0 if fails
**
**	ft_matchstart:
**	returns 1 if <match> matches starting charts of <ident>
**	returns 0 if fails
*/

int	ft_match(const char *ident, const char *match)
{
	int			index;

	index = 0;
	if (!ident)
		return (0);
	while (1)
	{
		if (ident[index] != match[index])
			break ;
		if (ident[index] == '\0' && match[index] == '\0')
			return (1);
		index++;
	}
	return (0);
}

int	ft_matchend(const char *ident, const char *match)
{
	int			index;
	int			index_m;

	index = ft_strlen(ident) - ft_strlen(match);
	index_m = 0;
	if (!ident)
		return (0);
	while (1)
	{
		if (ident[index] != match[index_m])
			break ;
		if (ident[index] == '\0' && match[index_m] == '\0')
			return (1);
		index++;
		index_m++;
	}
	return (0);
}

int	ft_matchstart(const char *ident, const char *match)
{
	int			index;

	index = 0;
	while (index <= (int)ft_strlen(match) && match[index])
	{
		if (ident[index] != match[index] || ident[index] == '\0')
			return (0);
		index++;
	}
	return (1);
}
