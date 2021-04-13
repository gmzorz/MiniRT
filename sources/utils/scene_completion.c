/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scene_completion.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/02 15:07:43 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/13 11:47:06 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <unistd.h>
#include <minirt.h>

void	scene_completion(t_real *completion, t_real add)
{
	if (*completion == 0.0)
		console_putnn("|");
	if (floor(*completion) < floor(*completion + add))
		write(1, "=", 1);
	*completion += add;
	if (floor(*completion) == 50)
		write(1, "|\n", 2);
}
