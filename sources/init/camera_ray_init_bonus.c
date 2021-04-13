/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera_ray_init_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/15 15:22:30 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:31:00 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <scene.h>
# include <math.h>
# include <utils.h>
# include <buffer_bonus.h>

/*
**	Generic bokeh sampling
**	Pick random points in a circle and use those as sampling offsets
*/

static t_vec2	vec2_distr_spheric(void)
{
	t_real	rand;
	t_real	theta;
	t_vec2	out;

	rand = sqrt(rt_rand());
	theta = rt_rand() * PI_2;
	out.u = rand * cos(theta);
	out.v = rand * sin(theta);
	return (out);
}

/*
**	Anamorphic camera sampling, not using ellipse sampling
**	spherical sampling is close enough!
*/

static t_vec2	vec2_distr_anamorphic(void)
{
	t_vec2	out;

	out = vec2_distr_spheric();
	return ((t_vec2){out.u * 0.5, out.v});
}

/*
**	Rejection sampling (miss ? try again)
*/

static t_vec2	vec2_distr_shapemask(t_dof *params)
{
	t_real	rand[2];

	rand[0] = rt_urand();
	rand[1] = rt_urand();
	if (greyscale(get_uv_color_at(params->shape.map,
				(rand[0] + 1) * 0.5, (rand[1] + 1) * 0.5)) < rt_rand())
		return (vec2_distr_shapemask(params));
	return ((t_vec2){rand[0], rand[1]});
}

t_mat4	mat4_random_bokeh(t_mat4 in, t_vec3 dir, t_dof *params)
{
	t_vec3	axis[3];
	t_vec2	rand;
	t_vec3	focal_plane;
	t_mat4	out;

	if (params->shape.map && params->shape_type == DOF_SHAPEMASK)
		rand = vec2_distr_shapemask(params);
	else if (params->shape_type == DOF_SPHERICAL)
		rand = vec2_distr_spheric();
	else if (params->shape_type == DOF_ANAMORPHIC)
		rand = vec2_distr_anamorphic();
	else
		rand = (t_vec2){rt_urand(), rt_urand()};
	axis[0] = vec3_mult_s(mat4_get(in, m_right), params->aperture * rand.u);
	axis[1] = vec3_mult_s(mat4_get(in, m_up), params->aperture * rand.v);
	focal_plane = get_point(mat4_get(in, m_origin), dir, params->focal_dist);
	out = mat4_add_vec(in, vec3_add(axis[0], axis[1]));
	return (mat4_lookat(mat4_get(out, m_origin), focal_plane));
}

t_bool	camera_ray_init(t_scene *scene, t_ray *ray, t_real u, t_real v)
{
	t_vec3		worldspace;
	t_mat4		cam_altered;

	worldspace.x = (2 * ((u + 0.5) / scene->mlx.width) - 1)
		* scene->camera->view_range * scene->ratio;
	worldspace.y = (1 - 2 * ((v + 0.5) / scene->mlx.height))
		* scene->camera->view_range;
	worldspace.z = 1;
	if (scene->camera->dof.enable && scene->viewport == brdf)
	{
		cam_altered = mat4_random_bokeh(scene->camera->world,
				mat4_mult_dir(scene->camera->world, worldspace),
				&scene->camera->dof);
		ray->origin = mat4_get(cam_altered, m_origin);
		ray->dir = mat4_get(cam_altered, m_forward);
	}
	else
	{
		ray->origin = mat4_get(scene->camera->world, m_origin);
		ray->dir = vec3_unit(mat4_mult_dir(scene->camera->world,
					worldspace));
	}
	ray->max = M_INFINITY;
	return (true);
}

#endif
