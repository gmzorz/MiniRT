/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_light_push.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 13:05:29 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:42:03 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <error.h>

t_bool	light_push_back(t_lights **list, t_lights *light)
{
	t_lights		*start;

	start = *list;
	if (start)
	{
		while (start->next)
			start = start->next;
		start->next = light;
		if (start->next == NULL)
			return (error_msg(ERR_ALLOC_LIGHT));
	}
	else
	{
		*list = light;
		if (*list == NULL)
			return (error_msg(ERR_ALLOC_LIGHT));
		start = *list;
	}
	return (true);
}
