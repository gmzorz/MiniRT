/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handler.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/10 12:04:03 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 23:52:51 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>
#include <scene.h>
#include <jump_tables.h>
#include <stdio.h>

int	key_handle(t_key key, t_scene *scene)
{
	int		idx;

	idx = 0;
	if (key != Enter && scene->viewport == shaded)
		scene->viewport = flat;
	if (!jump_key(scene, key))
		return (1);
	if (update(scene) == false)
		free_and_exit(scene);
	return (1);
}
