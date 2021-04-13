/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   construct.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/31 12:28:23 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:51:32 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <jump_tables.h>
#include <unistd.h>

t_bool	construct(t_shapes **list)
{
	t_shapes	*cur_shape;
	int			idx;

	cur_shape = *list;
	while (cur_shape != NULL)
	{
		idx = 0;
		jump_construct(cur_shape);
		cur_shape = cur_shape->next;
	}
	return (true);
}
