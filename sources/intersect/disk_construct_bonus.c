/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   disk_construct_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/18 11:29:18 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 17:37:22 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <init.h>
# include <math.h>

t_bool	disk_construct(t_shapes *catch)
{
	t_disk	*disk;
	t_vec3	bbext;

	disk = catch->shape;
	if (vec3_cmp_s(disk->span_a, 0.0))
		vec3_local_coords(disk->normal, &disk->span_a, &disk->span_b);
	volume_init(&catch->volume);
	bbext = (t_vec3){
		disk->radius * sqrt(1.0 - disk->normal.x * disk->normal.x),
		disk->radius * sqrt(1.0 - disk->normal.y * disk->normal.y),
		disk->radius * sqrt(1.0 - disk->normal.z * disk->normal.z)};
	volume_add_vec(&catch->volume, vec3_sub(disk->origin, bbext));
	volume_add_vec(&catch->volume, vec3_add(disk->origin, bbext));
	return (true);
}

#endif
