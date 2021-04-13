/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shaded.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/23 15:41:34 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:42:58 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 0
# include <scene.h>
# include <utils.h>
# include <libft.h>

/*
**	Trace a new ray from point of intersection towards light
**	If the ray intersects, and the distance towards said intersection is smaller
**	than the distance to the light, return true
*/

static t_bool	is_shadow(t_scene *scene, t_vec3 origin, t_vec3 dir)
{
	t_hitrecord		shadow;

	ft_memset(&shadow, 0, sizeof(t_hitrecord));
	shadow.ray.dir = vec3_unit(dir);
	shadow.ray.origin = vec3_add(origin,
			vec3_mult_s(shadow.ray.dir, M_EPSILON));
	shadow.ray.max = M_INFINITY;
	shadow.distance = M_INFINITY;
	intersect(scene->shapes, &shadow);
	if (shadow.distance > vec3_mag(dir))
		return (false);
	return (true);
}

t_rgb	s_shaded(t_scene *scene, t_hitrecord *rec)
{
	t_rgb			l_diffuse;
	t_lights		*lights;

	lights = scene->lights;
	l_diffuse = vec3_mult(rec->color, scene->ambient_color);
	while (lights != NULL)
	{
		lights->dir = vec3_sub(lights->origin, rec->point);
		if (is_shadow(scene, rec->point, lights->dir) == false)
		{
			lights->angle = clamp(vec3_dot(vec3_unit(lights->dir),
						rec->normal), 0, 1);
			l_diffuse = vec3_add(l_diffuse,
					vec3_mult_s(lights->color, lights->angle));
		}
		lights = lights->next;
	}
	return (vec3_clamp(vec3_mult(rec->color, l_diffuse), 0.0, 1.0));
}

#endif
