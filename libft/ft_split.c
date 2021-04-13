/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/29 16:42:11 by goosterl      #+#    #+#                 */
/*   Updated: 2019/12/02 20:04:14 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*** split rewritten because my old one was too long
*/

static int	ft_cw(char const *s, char c)
{
	int		count;
	int		i;

	i = 0;
	if (s[0] == '\0')
		return (0);
	if (c == '\0' && s)
		return (1);
	count = 1;
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
			count++;
		i++;
	}
	return (count);
}

static void	ft_free(char **strmem, int x)
{
	while (x)
	{
		x--;
		free(strmem[x]);
	}
	free(strmem);
}

static char	**ft_write(char *str, char **split, char c, int words)
{
	int		x;
	int		i;
	int		j;

	i = 0;
	x = 0;
	while (str[i] && x < words)
	{
		j = 0;
		while (str[i + j] != c && str[i + j] != '\0')
			j++;
		split[x] = ft_substr(str, i, j);
		if (!split[x])
		{
			ft_free(split, x);
			return (NULL);
		}
		x++;
		i += j;
		while (str[i] == c && str[i] != '\0')
			i++;
	}
	split[words] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	char	*str;
	char	*trim;
	int		words;

	if (!s)
		return (NULL);
	trim = (char *)malloc(sizeof(char) * 2);
	if (!trim)
		return (NULL);
	trim[0] = c;
	trim[1] = '\0';
	str = ft_strtrim(s, trim);
	free(trim);
	if (!str)
		return (NULL);
	words = ft_cw(str, c);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	split = ft_write(str, split, c, words);
	free(str);
	return (split);
}
