/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 14:53:12 by goosterl      #+#    #+#                 */
/*   Updated: 2019/11/28 21:52:32 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*m;
	size_t			i;

	i = 0;
	m = (unsigned char *)b;
	while (i < len)
	{
		m[i] = c;
		i++;
	}
	return (b);
}
