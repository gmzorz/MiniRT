/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clamp.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 15:25:25 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 23:09:43 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <alias.h>

t_real	clamp(t_real in, t_real min, t_real max)
{
	if (in < min)
		return (min);
	if (in > max)
		return (max);
	return (in);
}
