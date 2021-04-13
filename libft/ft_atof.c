/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atof.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/07 15:08:19 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/13 14:04:36 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	retrieve_int(const char *str, int *index, double *final)
{
	while (ft_isdigit(str[*index]))
	{
		*final = (*final * 10) + (str[*index] - '0');
		*index += 1;
		if (!ft_isdigit(str[*index]) && str[*index] != '\0'\
			&& str[*index] != '.')
			return (0);
	}
	return (1);
}

static int	retrieve_dec(const char *str, int *index, double *final)
{
	double	decimal;

	decimal = 0.1;
	if (!(str[*index] == '.'))
		return (1);
	*index += 1;
	while (ft_isdigit(str[*index]))
	{
		*final += decimal * (str[*index] - '0');
		decimal *= 0.1;
		*index += 1;
		if (!ft_isdigit(str[*index]) && str[*index] != '\0'\
			&& str[*index] != '.')
			return (0);
	}
	return (1);
}

static int	isalfloat(const char *str)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] != '.' && str[index] != '+' && str[index] != '-'\
			&& !ft_isdigit(str[index]))
			return (0);
		index++;
	}
	return (1);
}

int	ft_atof(const char *str, double *num)
{
	int		index;
	double	negative;

	index = 0;
	negative = 1;
	if (str == NULL || num == NULL || str[0] == '\0')
		return (0);
	*num = 0;
	if (!isalfloat(str))
		return (0);
	while (ft_isspace(str[index]))
		index++;
	if (str[index] == '-')
		negative = -negative;
	if (str[index] == '-' || str[index] == '+')
		index += 1;
	if (!retrieve_int(str, &index, num))
		return (0);
	if (!retrieve_dec(str, &index, num))
		return (0);
	*num *= negative;
	return (1);
}
