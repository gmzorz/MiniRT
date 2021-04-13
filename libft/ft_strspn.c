/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strspn.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/10 16:49:53 by goosterl      #+#    #+#                 */
/*   Updated: 2020/08/10 17:28:42 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcspn(const char *str, const char *accept)
{
	size_t	ret;

	ret = 0;
	if (accept[0] == '\0')
		return (ft_strlen(str));
	while (str[ret] != '\0')
	{
		if (ft_strchr(accept, str[ret]))
			return (ret);
		ret++;
	}
	return (ft_strlen(str));
}

size_t	ft_strspn(const char *str, const char *accept)
{
	size_t	size;
	size_t	ret;

	ret = 0;
	size = 0;
	while (str[size] != '\0')
	{
		if (!(ft_strchr(accept, str[size])))
			return (ret);
		else
			ret++;
		size++;
	}
	return (0);
}
