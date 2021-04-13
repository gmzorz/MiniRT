/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   aabb_test.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/14 15:12:49 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 17:57:40 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>
#include <utils.h>

static t_vec3	get_minmax(const t_aabb volume, const int sign)
{
	if (sign)
		return (volume.max);
	return (volume.min);
}

static t_bool	aabb_intersect(const t_ray ray, t_aabb volume)
{
	t_vec3	inverse;
	t_vec3	sign;
	t_aabb	test;

	inverse = vec3_div((t_vec3){1.0, 1.0, 1.0}, ray.dir);
	sign = (t_vec3){inverse.x < 0, inverse.y < 0, inverse.z < 0};
	test.min.x = (get_minmax(volume, 0 - sign.x).x - ray.origin.x) * inverse.x;
	test.max.x = (get_minmax(volume, 1 - sign.x).x - ray.origin.x) * inverse.x;
	test.min.y = (get_minmax(volume, 0 - sign.y).y - ray.origin.y) * inverse.y;
	test.max.y = (get_minmax(volume, 1 - sign.y).y - ray.origin.y) * inverse.y;
	if (test.min.x > test.max.y || test.min.y > test.max.x)
		return (false);
	test.min.x = setcnd(test.min.y > test.min.x, test.min.y, test.min.x);
	test.min.x = setcnd(test.min.y > test.min.x, test.min.y, test.min.x);
	test.max.x = setcnd(test.max.y < test.max.x, test.max.y, test.max.x);
	test.min.z = (get_minmax(volume, 0 - sign.z).z - ray.origin.z) * inverse.z;
	test.max.z = (get_minmax(volume, 1 - sign.z).z - ray.origin.z) * inverse.z;
	if (test.min.x > test.max.z || test.min.z > test.max.x)
		return (false);
	test.min.x = setcnd(test.min.z > test.min.x, test.min.z, test.min.x);
	test.max.x = setcnd(test.max.z < test.max.x, test.max.z, test.max.x);
	if (test.min.x >= 0.0 || test.max.x >= 0.0)
		return (true);
	return (false);
}

t_bool	aabb_test(const t_ray ray, const t_aabb volume, t_bool *hit)
{
	if (volume.using == false)
		return (true);
	if (aabb_intersect(ray, volume))
	{
		if (hit)
			*hit = true;
		return (true);
	}
	return (false);
}
