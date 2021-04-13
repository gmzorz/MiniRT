/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   normals_bonus.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/12 11:34:16 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:21:07 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>

t_rgb	s_normals(t_scene *scene, t_hitrecord *rec)
{
	(void)scene;
	return (vec3_mult_s(vec3_add_s(rec->normal, 1), 0.5));
}
