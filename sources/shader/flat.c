/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flat.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/13 15:22:53 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:42:51 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>
#include <utils.h>
#include <math.h>

/*
**	Cool studio shading trick, thanks to @suricrasia
**	That weird .577 number is pretty much the square root of .333
**	Multiplying is faster, so we ditch the square root & divisions
*/

t_rgb	s_flat(t_scene *scene, t_hitrecord *rec)
{
	t_real	scalar;
	t_rgb	color;

	(void)scene;
	scalar = 0.0;
	if (!vec3_cmp_s(rec->normal, 0.0))
	{
		color = (t_vec3){
			sin(rec->normal.x * 2.5) * 0.5 + 0.5,
			sin(rec->normal.y * 2.5) * 0.5 + 0.5,
			sin(rec->normal.z * 2.5) * 0.5 + 0.5};
		scalar = vec3_mag(color) * 0.5773502692;
	}
	color = vec3_mult(rec->color, (t_vec3){scalar, scalar, scalar});
	return (vec3_clamp(color, 0, 1));
}
