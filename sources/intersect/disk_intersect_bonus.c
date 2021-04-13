/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   disk_intersect_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/17 14:22:41 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:28:36 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <scene.h>
# include <utils.h>
# include <math.h>

static t_bool	disk_hit(t_shapes *catch, t_hitrecord *rec, t_real t, t_vec3 p)
{
	t_disk	*disk;

	disk = catch->shape;
	rec->point = p;
	rec->tex.u = vec3_dot(vec3_div_s(vec3_sub(p, disk->origin), disk->radius),
			disk->span_a) * 0.5 + 0.5;
	rec->tex.v = vec3_dot(vec3_div_s(vec3_sub(p, disk->origin), disk->radius),
			disk->span_b) * 0.5 + 0.5;
	rec->distance = t;
	rec->ref = catch;
	return (true);
}

t_bool	disk_intersect(t_shapes *catch, t_hitrecord *rec)
{
	t_disk	*disk;
	t_real	parallel;
	t_vec3	dist;
	t_real	t;
	t_vec3	p;

	disk = catch->shape;
	parallel = vec3_dot(disk->normal, rec->ray.dir);
	if (fabs(parallel) < M_EPSILON)
		return (false);
	dist = vec3_sub(disk->origin, rec->ray.origin);
	t = vec3_dot(dist, disk->normal) / parallel;
	if (t <= 0 || t > rec->distance)
		return (false);
	p = get_point(rec->ray.origin, rec->ray.dir, t);
	if (vec3_mag(vec3_sub(p, disk->origin)) > disk->radius)
		return (false);
	rec->normal = disk->normal;
	if (parallel > 0)
		rec->normal = vec3_negate(disk->normal);
	return (disk_hit(catch, rec, t, p));
}

#endif
