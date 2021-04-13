/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sphere_construct.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/14 11:43:30 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:51:47 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <shapes.h>
#include <init.h>

t_bool	sphere_construct(t_shapes *catch)
{
	t_sphere	*sphere;

	sphere = catch->shape;
	volume_init(&catch->volume);
	catch->volume.min = vec3_sub_s(sphere->origin, sphere->radius);
	catch->volume.max = vec3_add_s(sphere->origin, sphere->radius);
	return (true);
}
