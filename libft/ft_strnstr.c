/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 14:57:07 by goosterl      #+#    #+#                 */
/*   Updated: 2019/11/28 22:09:58 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		if (haystack[i] == needle[j] && (i + ft_strlen(needle)) <= len)
		{
			while (needle[j] == haystack[i + j] && needle[j] != '\0')
				j++;
			if (j == ft_strlen(needle))
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
