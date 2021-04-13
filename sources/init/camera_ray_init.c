/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera_ray_init.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/15 15:22:30 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:38:35 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 0
# include <scene.h>

t_bool	camera_ray_init(t_scene *scene, t_ray *ray, t_real u, t_real v)
{
	t_vec3		worldspace;

	worldspace.x = (2 * ((u + 0.5) / scene->mlx.width) - 1)
		* scene->camera->view_range * scene->ratio;
	worldspace.y = (1 - 2 * ((v + 0.5) / scene->mlx.height))
		* scene->camera->view_range;
	worldspace.z = 1;
	ray->origin = mat4_get(scene->camera->world, m_origin);
	ray->dir = vec3_unit(mat4_mult_dir(scene->camera->world,
				worldspace));
	ray->max = M_INFINITY;
	return (true);
}

#endif
