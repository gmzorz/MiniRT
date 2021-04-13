/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_lights.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/31 16:59:02 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:39:24 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <unistd.h>
#include <stdlib.h>

void	free_lights(t_lights **lights)
{
	t_lights		*start;
	t_lights		*next;

	console_put(RT_FREE_CAM);
	start = *lights;
	while (start)
	{
		next = start->next;
		free(start);
		start = next;
	}
	*lights = NULL;
}
