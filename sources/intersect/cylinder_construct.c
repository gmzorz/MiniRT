/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cylinder_construct.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/22 16:09:23 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 17:59:30 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 0
# include <shapes.h>
# include <math.h>
# include <init.h>

t_bool	cylinder_construct(t_shapes *catch)
{
	t_cylinder	*cyl;
	t_vec3		nml_inv;
	t_vec3		center_rad;

	cyl = catch->shape;
	cyl->height_d2 = cyl->height / 2;
	cyl->half_height = vec3_mult_s(cyl->normal, cyl->height / 2);
	cyl->top = vec3_add(cyl->origin, cyl->half_height);
	cyl->bottom = vec3_sub(cyl->origin, cyl->half_height);
	cyl->diff = vec3_sub(cyl->bottom, cyl->top);
	nml_inv = vec3_sub((t_vec3){1.0, 1.0, 1.0}, vec3_div_s(
				vec3_mult(cyl->diff, cyl->diff),
				vec3_dot(cyl->diff, cyl->diff)));
	center_rad = (t_vec3){
		cyl->radius * sqrt(nml_inv.x),
		cyl->radius * sqrt(nml_inv.y),
		cyl->radius * sqrt(nml_inv.z)};
	volume_init(&catch->volume);
	volume_add_vec(&catch->volume, vec3_sub(cyl->top, center_rad));
	volume_add_vec(&catch->volume, vec3_add(cyl->top, center_rad));
	volume_add_vec(&catch->volume, vec3_sub(cyl->bottom, center_rad));
	volume_add_vec(&catch->volume, vec3_add(cyl->bottom, center_rad));
	return (true);
}

#endif
