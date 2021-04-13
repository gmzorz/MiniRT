/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 14:54:52 by goosterl      #+#    #+#                 */
/*   Updated: 2019/11/28 22:12:06 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	int		occ;
	char	ch;
	char	*str;

	str = (char *)s;
	ch = (char)c;
	i = 0;
	occ = -1;
	while (i <= ft_strlen((char *)str))
	{
		if (str[i] == ch)
			occ = i;
		i++;
	}
	if (occ != -1)
		return ((char *)str + occ);
	return (NULL);
}
