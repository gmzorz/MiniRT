/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_shape.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/11 14:40:20 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:41:53 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <error.h>
#include <libft.h>
#include <init.h>

static t_shapes	*new_shape(void *shape,
	t_material mat, t_shapetype type)
{
	t_shapes		*element;

	element = (t_shapes *)ft_calloc(1, sizeof(t_shapes));
	if (element == NULL)
		return (NULL);
	element->shape = shape;
	element->type = type;
	element->mat = mat;
	element->construct = true;
	volume_init(&element->volume);
	return (element);
}

t_bool	shape_push_back(t_shapes **list, void *shape, t_material mat,
	t_shapetype type)
{
	t_shapes		*start;

	if (!shape)
		return (error_msg(ERR_SHAPE_ADD));
	start = *list;
	if (start)
	{
		while (start->next)
			start = start->next;
		start->next = new_shape(shape, mat, type);
		if (start->next == NULL)
			return (error_msg(ERR_ALLOC_SHAPE));
	}
	else
	{
		*list = new_shape(shape, mat, type);
		if (*list == NULL)
			return (error_msg(ERR_ALLOC_SHAPE));
		start = *list;
	}
	return (true);
}
