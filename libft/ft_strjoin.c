/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 18:56:59 by goosterl      #+#    #+#                 */
/*   Updated: 2019/11/28 22:04:52 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 == NULL)
		return (NULL);
	new = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (new == NULL)
		return (NULL);
	while (i < ft_strlen((char *)s1))
	{
		new[i] = s1[i];
		i++;
	}
	while (j < ft_strlen((char *)s2))
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}
