/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 16:22:27 by goosterl      #+#    #+#                 */
/*   Updated: 2019/11/28 22:04:21 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	void	*str;
	size_t	len;

	len = ft_strlen((char *)s1) + 1;
	str = (char *)malloc(len);
	if (str == NULL)
		return (NULL);
	return ((char *)ft_memcpy(str, s1, len));
}
