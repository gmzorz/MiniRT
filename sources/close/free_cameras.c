/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_cameras.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/11 13:54:37 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:39:14 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <stdlib.h>
#include <unistd.h>

void	free_cameras(t_camlist **list)
{
	t_camlist		*start;
	t_camlist		*next;

	console_put(RT_FREE_CAM);
	start = *list;
	while (start)
	{
		next = start->next;
		free(start->cam);
		free(start);
		start = next;
	}
	*list = NULL;
}
