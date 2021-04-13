/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shaded_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/23 15:41:34 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:24:01 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <scene.h>
# include <utils.h>
# include <math.h>
# include <libft.h>
# include <unistd.h>

/*
**	Check if reflection material exists, lower the scene depth and compute
**	the reflected ray off the surface based on the ray direction and the
**	surface normal, then trace again and retrieve that color to mix it with
**	the original traced color (based on reflection material)
*/

static void	reflect(t_scene *scene, t_hitrecord *rec, t_rgb *aggr)
{
	t_ray			reflect;
	t_rgb			color;
	t_real			dir_dot;

	color = vec3_zero();
	if (vec3_cmp(rec->reflection, color))
		return ;
	reflect.max = rec->ray.max - (M_INFINITY / (MAX_BOUNCE + 1));
	dir_dot = vec3_dot(rec->ray.dir, rec->normal);
	reflect.dir = vec3_unit(vec3_sub(rec->ray.dir,
				vec3_mult_s(vec3_mult_s(rec->normal, 2), dir_dot)));
	reflect.origin = vec3_add(rec->point, vec3_mult_s(reflect.dir,
				M_EPSILON));
	trace(scene, reflect, &color);
	*aggr = vec3_mult(*aggr,
			vec3_sub((t_vec3){1.0, 1.0, 1.0}, rec->reflection));
	*aggr = vec3_add(*aggr, vec3_mult(color, rec->reflection));
}

/*
**	Specular highlights
**	Compute the smoothness of the object using a phong exponent
*/

t_rgb	gloss(t_hitrecord *rec, t_lights *light)
{
	t_rgb	color;
	t_real	cossigma;
	t_vec3	spot;

	if (vec3_cmp(rec->specular, vec3_zero()))
		return (vec3_zero());
	color = vec3_zero();
	spot = vec3_sub(vec3_unit(light->dir), vec3_mult_s(rec->normal,
				2 * light->angle * light->lp_bias));
	cossigma = vec3_dot(rec->ray.dir, spot);
	if (cossigma > 0)
		color = vec3_add(color,
				vec3_mult_s(light->color, pow(cossigma, rec->gloss)));
	return (vec3_mult(color, rec->specular));
}

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

/*
**	For every light, normalize angle towards light and use that as scalar
**	value for the initial light brightness affecting the surface
*/

t_rgb	s_shaded(t_scene *scene, t_hitrecord *rec)
{
	t_rgb			aggr;
	t_lights		*lights;

	lights = scene->lights;
	aggr = vec3_mult(rec->color, scene->ambient_color);
	while (lights != NULL)
	{
		lights->dir = vec3_sub(lights->origin, rec->point);
		lights->lp_bias = setcnd(vec3_cmp(lights->normal, vec3_zero()),
				1, vec3_dot(lights->normal, vec3_unit(lights->dir)));
		if (is_shadow(scene, rec->point, lights->dir) == false
			&& lights->lp_bias > 0)
		{
			lights->angle = clamp(vec3_dot(vec3_unit(lights->dir),
						rec->normal), 0, 1);
			aggr = vec3_add(aggr, vec3_mult_s(lights->color,
						lights->angle * lights->lp_bias));
			aggr = vec3_add(aggr, gloss(rec, lights));
		}
		lights = lights->next;
	}
	aggr = vec3_clamp(vec3_mult(rec->color, aggr), 0.0, 1.0);
	if (rec->ray.max > 0)
		reflect(scene, rec, &aggr);
	return (aggr);
}

#endif
