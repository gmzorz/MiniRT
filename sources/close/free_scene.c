/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_scene.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/11 13:59:09 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:39:09 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <stdlib.h>

void	free_scene(t_scene *scene)
{
	console_put(RT_FREE_SCENE);
	free(scene->mlx.ptr);
	free(scene);
}
