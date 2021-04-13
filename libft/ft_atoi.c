/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 15:00:36 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/13 14:06:10 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str, int *num)
{
	int		index;
	long	ret;

	index = 0;
	ret = 0;
	if (!str)
		return (0);
	if (!num)
		return (-1);
	if (str[index] == '-')
		index++;
	while (str[index] && ft_isalnum(str[index]))
	{
		ret = 10 * ret + (str[index] - '0');
		index++;
	}
	if (index == 0 || (str[0] == '-' && index == 1))
		return (0);
	if (str[0] == '-')
		*num = -ret;
	else
		*num = ret;
	return (index);
}
