/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scene.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:36:54 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/09 16:05:52 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H
# include <buffer.h>
# include <shapes.h>
# include <elements.h>
# include <ray.h>
# if IS_BONUS == 1
#  include <scene_bonus.h>
# else

typedef enum e_mode
{
	unlit,
	flat,
	shaded,
	aabb,
	none
}	t_mode;

/*
**	Record containing saved data from intersection
**	 ray		- Calculated ray being shot, initialized before intersection
**	 *ref		- Reference to shape being intersected
**	 distance	- Distance to point of intersection
**	 point		- point of intersection
**	 normal		- Normal at point
*/
typedef struct s_hitrecord
{
	t_ray		ray;
	t_shapes	*ref;
	t_real		distance;
	t_rgb		color;
	t_vec3		point;
	t_vec3		normal;
	t_bool		aabb_hit;
}	t_hitrecord;

typedef struct s_scene
{
	char		*file;
	char		*line;
	t_bool		bmp_save;
	t_real		ratio;
	t_window	mlx;
	t_mode		viewport;
	t_buffer	main;
	int			u;
	int			v;
	t_real		completion;
	t_real		prog_add;
	t_vec2		screen;
	t_real		ambience;
	t_rgb		ambient_color;
	t_shapes	*shapes;
	t_lights	*lights;
	t_camlist	*cameras;
	t_camera	*camera;
	int			cam_idx;
	int			cam_count;
}	t_scene;

# endif
# define DEBUG_AABB "Displaying bounding volumes"
# define DEBUG_UNLIT "Displaying unlit colors"
# define DEBUG_FLAT "Displaying unlit colors"

/*
**	main update function
*/
t_bool	update(t_scene *scene);

/*
**	calculate shape variables that do not follow the per pixel tracing algorithm
*/
t_bool	construct(t_shapes **shapes);

/*
**	Perform a set of actions for each pixel
*/
t_bool	render(t_scene *scene);

/*
**	Initialize new hitrecord
**	Find winning intersection (&shape, distance, normals...)
**	Get winning attributes (normal, point, texcoords)
**	If shape is referenced (!= NULL), apply shading
**	If not, apply background color to *buf_color and return (miss)
*/
t_bool	trace(t_scene *scene, t_ray ray, t_rgb *buf_color);

/*
**	Test against aabb (axis aligned bounding box)
**	See whether simple box is being intersected (cheap test)
*/
t_bool	aabb_test(const t_ray ray, const t_aabb volume, t_bool *hit);

/*
**	Calculate intersection tests for each shape in the scene
**	Save winning shape as reference and winning distance in hitrecord <*rec>
*/
t_bool	intersect(const t_shapes *shapes, t_hitrecord *rec);

/*
**	Add shape reference and new distance to hitrecord if distance < rec->distance
*/
t_bool	hit(t_shapes *shape, t_hitrecord *rec, t_real distance);

/*
**	For each light, check if light is facing normal of hitrecord <rec>
*/
t_bool	compute_lights(t_scene *scene, t_hitrecord *rec, t_rgb *color);

/*
**	Add vector element to volume IF vector exceeds current bounding volume
*/
t_bool	volume_add_vec(t_aabb *volume, t_vec3 vec);

/*
**	shape_construct()
**	 Compute variables that do not follow the per pixel tracing algorithm
**	 and set up bounding volume for cheap intersection test
*/

t_bool	sphere_construct(t_shapes *catch);
t_bool	plane_construct(t_shapes *catch);
t_bool	square_construct(t_shapes *catch);
t_bool	cylinder_construct(t_shapes *catch);
t_bool	triangle_construct(t_shapes *catch);

/*
**	shape_intersect()
**	 Check whether ray rec->ray intersects with shape
*/

t_bool	sphere_intersect(t_shapes *catch, t_hitrecord *rec);
t_bool	plane_intersect(t_shapes *catch, t_hitrecord *rec);
t_bool	square_intersect(t_shapes *catch, t_hitrecord *rec);
t_bool	cylinder_intersect(t_shapes *catch, t_hitrecord *rec);
t_bool	triangle_intersect(t_shapes *catch, t_hitrecord *rec);

/*
**	Shaders
**	how objects are displayed in the scene
**	non-bonus includes:
**	- unlit (color only)
**	- flat (shaded using three directional lighting setup)
**	- shaded (rendered)
*/
t_rgb	shade(t_scene *scene, t_hitrecord *rec);

/*
**	Unlit
**	returns material color
*/
t_rgb	s_unlit(t_scene *scene, t_hitrecord *rec);

/*
**	Flat
**	return material color times the dot product between ray dir and surf normal
**	a cheap shading method that uses the camera as a light
*/
t_rgb	s_flat(t_scene *scene, t_hitrecord *rec);

/*
**	Shaded
**	Applies all the lights and shadows
*/
t_rgb	s_shaded(t_scene *scene, t_hitrecord *rec);

/*
**	Aabb
**	Displays bounding volumes (if set)
*/
t_rgb	s_aabb(t_scene *scene, t_hitrecord *rec);

#endif
