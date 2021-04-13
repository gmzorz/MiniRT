/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   setcnd.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/15 11:43:45 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:17:27 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <alias.h>

t_real	setcnd(int condition, t_real pos, t_real neg)
{
	if (condition)
		return (pos);
	return (neg);
}
