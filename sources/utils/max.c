/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   max.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/27 13:41:34 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:15:46 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <alias.h>

t_real	max(t_real one, t_real two)
{
	if (one > two)
		return (one);
	return (two);
}
