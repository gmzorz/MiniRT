/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   brdf_trace_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/01 16:38:05 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 23:21:27 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <scene.h>
# include <utils.h>
# include <libft.h>
# include <vector_bonus.h>

static t_rgb	brdf_reflect(t_scene *scene, t_hitrecord *rec)
{
	t_rgb	color;
	t_ray	ray;
	t_vec3	roughness;

	roughness = (t_vec3){
		rt_urand() * rec->roughness,
		rt_urand() * rec->roughness,
		rt_urand() * rec->roughness};
	ray.dir = vec3_unit(vec3_add(vec3_reflect(rec->ray.dir,
					rec->normal), roughness));
	ray.origin = vec3_add(rec->point, vec3_mult_s(ray.dir, M_EPSILON));
	color = vec3_mult(brdf_trace(scene, ray, rec->depth - 1),
			rec->reflection);
	color = vec3_mult_s(vec3_mult(color, rec->color),
			vec3_dot(rec->normal, ray.dir));
	return (color);
}

static t_rgb	brdf_diffuse(t_scene *scene, t_hitrecord *rec)
{
	t_rgb	color;
	t_ray	ray;

	ray.dir = vec3_hsphere(rec->normal, rt_rand(), rt_rand());
	ray.origin = vec3_add(rec->point, vec3_mult_s(ray.dir, M_EPSILON));
	color = brdf_trace(scene, ray, rec->depth - 1);
	color = vec3_mult_s(vec3_mult(color, rec->color),
			vec3_dot(rec->normal, ray.dir));
	return (color);
}

static t_rgb	cast_brdf_ray(t_scene *scene, t_hitrecord *rec)
{
	if (rec->roughness > rt_rand())
		return (brdf_diffuse(scene, rec));
	return (brdf_reflect(scene, rec));
}

t_rgb	brdf_trace(t_scene *scene, t_ray ray, int depth)
{
	t_hitrecord		rec;
	t_rgb			aggr;
	t_rgb			traced;

	aggr = vec3_zero();
	ft_memset(&rec, 0, sizeof(t_hitrecord));
	rec.ray = ray;
	rec.ray.max = M_INFINITY;
	rec.distance = M_INFINITY;
	rec.depth = depth;
	if (intersect(scene->shapes, &rec))
	{
		set_textures(&rec, true);
		aggr = vec3_mult(rec.emission, rec.color);
		if (depth < 0)
			return (aggr);
		traced = cast_brdf_ray(scene, &rec);
		aggr = vec3_add(aggr, traced);
		return (aggr);
	}
	return (set_skybox(scene, vec3_unit(ray.dir), depth != scene->brdf_depth));
}

#endif
