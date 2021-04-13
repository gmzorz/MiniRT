/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_shapes.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/31 16:55:33 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:39:19 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 0
# include <minirt.h>
# include <shapes.h>
# include <stdlib.h>

void	free_shapes(t_shapes **shapes)
{
	t_shapes		*start;
	t_shapes		*next;

	console_put(RT_FREE_SHAPES);
	start = *shapes;
	while (start)
	{
		next = start->next;
		free(start->shape);
		free(start);
		start = next;
	}
	*shapes = NULL;
}

#endif
