/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   aabb.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/18 12:55:35 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:43:02 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>

t_rgb	s_aabb(t_scene *scene, t_hitrecord *rec)
{
	(void)scene;
	if (rec->aabb_hit)
		return ((t_vec3){0.75, 0.0, 0.0});
	return ((t_vec3){0.5, 0.5, 0.5});
}
