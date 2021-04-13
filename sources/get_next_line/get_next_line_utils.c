/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 15:13:01 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:23:10 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

int	gnl_strlen_nl(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	*gnl_memcpy(char *dst, char *src, size_t n)
{
	int		i;

	i = 0;
	if (dst == 0 && src == 0)
		return (0);
	while (n > 0)
	{
		dst[i] = src[i];
		i++;
		n--;
	}
	dst[i] = '\0';
	return (dst);
}

size_t	gnl_strlen_c(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c)
		i++;
	return (i);
}

char	*gnl_strndup(char *s1, size_t len)
{
	size_t	i;
	char	*ret;

	i = 0;
	ret = malloc(sizeof(*s1) * (len + 1));
	if (ret == NULL)
		return (0);
	while (i < len)
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	i;
	size_t	len;

	i = 0;
	len = gnl_strlen_c(s1, '\0') + gnl_strlen_c(s2, '\0');
	if (s1 == NULL)
		return (NULL);
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	while (*s1)
	{
		new[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		new[i] = *s2;
		s2++;
		i++;
	}
	new[i] = '\0';
	return (new);
}
