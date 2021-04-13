/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   plane_construct.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/21 14:40:59 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:52:10 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 0
# include <scene.h>

t_bool	plane_construct(t_shapes *catch)
{
	t_plane		*plane;

	plane = catch->shape;
	catch->volume.using = false;
	return (true);
}

#endif
