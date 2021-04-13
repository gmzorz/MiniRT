/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   greyscale_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/06 14:41:02 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:57:40 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <color.h>

t_real	greyscale(t_rgb color)
{
	return ((color.x + color.y + color.z) * 0.3333333);
}
