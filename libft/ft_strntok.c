/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strntok.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/10 15:27:50 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/13 14:05:33 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

/*
**	ft_strntok - extract tokens from strings
**
**	<const char *str> 		input string
**	<const char *delim> 	delimiter set
**	<int count>				delimiter count, takes string before delimiter
**
**	Parses a string into a sequence of tokens.
**	Splits based on delimiter(s) and returns sequence
**
**	Similar to MS-DOS FOR /F "tokens=* delims=*"
*/

char	*ft_strntok(char *str, char *delim, int count)
{
	char	*input;
	char	*tokens;
	int		len;

	len = 0;
	if (!str)
		return (NULL);
	input = ft_strdup(str);
	while (count)
	{
		input += ft_strspn(input, delim);
		input += ft_strcspn(input, delim);
		count--;
	}
	input += ft_strspn(input, delim);
	if (!(*input))
		return (NULL);
	if (count == 0)
	{
		len = ft_strcspn(input, delim);
		tokens = input + len;
		*tokens = '\0';
		return (tokens - len);
	}
	return (NULL);
}
