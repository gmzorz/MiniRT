/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   units_bonus.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/12 11:36:11 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:21:14 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>
#include <math.h>

t_rgb	s_units(t_scene *scene, t_hitrecord *rec)
{
	int		add;

	(void)scene;
	add = floor(rec->point.x + M_EPSILON)
		+ floor(rec->point.y + M_EPSILON)
		+ floor(rec->point.z + M_EPSILON);
	if (add % 2)
		return ((t_vec3){1.0, 1.0, 1.0});
	return (vec3_zero());
}
