/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scene_bonus.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:36:54 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/13 12:54:07 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_BONUS_H
# define SCENE_BONUS_H
# if IS_BONUS == 1
#  include <buffer.h>
#  include <vector.h>
#  include <alias.h>
#  include <shapes.h>
#  include <matrix.h>
#  include <elements.h>
#  include <ray.h>
#  include <pthread.h>
#  define SELECTION_UNDEFINED -1
#  define SELECTION_TRANSLATE 0
#  define SELECTION_ROTATE 1
#  define MAX_BOUNCE 4
#  define DEBUG_DOF "Displaying Depth of field focal plane"
#  define DEBUG_UNITS "Displaying units"
#  define DEBUG_NORMALS "Displaying normals"
#  define DEBUG_BRDF "Rendering BRDF..."
#  define DEBUG_UV "Displaying texture UV coordinates"

typedef enum e_mode
{
	unlit,
	flat,
	shaded,
	brdf,
	normals,
	units,
	uvs,
	aabb,
	dof,
	none
}	t_mode;

typedef struct s_hitrecord
{
	t_ray		ray;
	t_shapes	*ref;
	t_real		distance;
	t_rgb		color;
	t_rgb		specular;
	int			gloss;
	t_real		roughness;
	t_rgb		reflection;
	t_rgb		emission;
	t_vec3		point;
	t_vec3		normal;
	t_vec2		tex;
	t_bool		aabb_hit;
	int			depth;
}	t_hitrecord;

typedef struct s_scene
{
	char		*file;
	char		*line;
	t_bool		bmp_save;
	t_real		ratio;
	t_window	mlx;
	t_mode		viewport;
	int			viewport_scale;
	t_buffer	main;
	t_buffer	filter;
	t_buffer	selection;
	t_shapes	*selected_shape;
	int			selection_mode;
	t_vec3		selection_axis;
	int			u;
	int			v;
	t_real		completion;
	t_real		prog_add;
	t_vec2		screen;
	t_real		ambience;
	t_rgb		ambient_color;
	t_bool		aa_enable;
	t_bool		aa_accel;
	int			aa_samples;
	t_bool		sun;
	t_bool		sun_show;
	t_vec3		sun_direction;
	t_real		sun_size;
	t_real		sun_intensity;
	t_rgb		sun_color;
	t_material	skybox;
	t_bool		brdf;
	int			brdf_spp;
	int			brdf_depth;
	t_bool		brdf_threading;
	int			brdf_threadnum;
	t_bool		brdf_save;
	t_shapes	*shapes;
	t_lights	*lights;
	t_camlist	*cameras;
	t_texture	*textures;
	t_camera	*camera;
	int			cam_idx;
	int			cam_count;
	t_bool		do_update;
}	t_scene;

/*
**	BONUS:
**	Multithreading (BRDF ONLY)
*/
typedef struct s_thr_data
{
	int				idx;
	t_scene			*scene;
	t_real			*completion;
	pthread_mutex_t	*lock;
}	t_thr_data;

/*
**	BONUS:
**	Caps on cylinders
*/
t_bool	disk_intersect(t_shapes *catch, t_hitrecord *rec);
t_bool	disk_construct(t_shapes *catch);

/*
**	BONUS:
**	Cube
*/
t_bool	cube_intersect(t_shapes *catch, t_hitrecord *rec);
t_bool	cube_construct(t_shapes *catch);

/*
**	BONUS:
**	Pyramid
*/
t_bool	pyramid_intersect(t_shapes *catch, t_hitrecord *rec);
t_bool	pyramid_construct(t_shapes *catch);

/*
**	BONUS:
**	Triangle mesh
*/
t_bool	trimesh_construct(t_shapes *catch);
t_bool	trimesh_intersect(t_shapes *catch, t_hitrecord *rec);

/*
**	Mesh acceleration 
*/
t_bool	bvh_construct(t_trimesh *mesh);

/*
**	BONUS:
**	Skybox (dome)
**	Load skybox texture buffer and locate the UV coordinates according to the
**	ray direction inverse. if no skybox is set, return (0,0,0)
**	If env is true, the skybox/sun should be multiplied by its set emission
**	this means only objects are affected by the emitting skybox, whilst the
**	background remains a solid image.
*/
t_rgb	set_skybox(const t_scene *scene, const t_vec3 rd, const t_bool env);

/*
**	BONUS:
**	Sobel accelerated Supersampling anti aliasing
**	Take a copy of scene->main buffer as input source, detect edges using an
**	extended sobel kernel. Then scatter random rays per pixel according to
**	edgeness (approx 90% faster, but only when there is less detail)
*/
t_bool	sassaa(t_scene *scene);

/*
**	BONUS (not mandatory)
**	Bidirectional reflectance distribution
**	Global illumination for the most part
*/
t_bool	brdf_render(t_scene *scene);
t_bool	brdf_threading(t_scene *scene);
void	compute_pixel(t_scene *scene, t_vec2 frag);
t_rgb	brdf_trace(t_scene *scene, t_ray ray, int depth);

/*
**	BONUS:
**	"Rainbow effect" using surface normals
**	This is simply a way of displaying normals through color, we transform a
**	vector3 struct into a rgb format where unit length can only go above 0
**	-1.0 -> 0.0
**	-0.5 -> 0.25
**	0.0 -> 0.5
**	0.5 -> 0.75
*/
t_rgb	s_normals(t_scene *scene, t_hitrecord *rec);

/*
**	BONUS:
**	Checkerboard, by means of displaying unit length blocks
**	we check if the floor of point P (intersection) % 2 == 0, all even blocks
**	will be colored black and all uneven blocks will be white
*/
t_rgb	s_units(t_scene *scene, t_hitrecord *rec);

/*
**	BONUS:
**	UV texturing/coordinates
**	This shader displays the uv coordinates of the surface (in color),
**	which corresponds to the texture that has it's dimensions clamped to
**	[0.0 ... 1.0]
*/
t_rgb	s_uvs(t_scene *scene, t_hitrecord *rec);

/*
**	BONUS (not mandatory):
**	Depth of field debugger
**	Displays the focal plane and falloff
*/
t_rgb	s_dof(t_scene *scene, t_hitrecord *rec);

/*
**	BONUS:
**	Color filter, Drawing outlines over shapes that have been selected
**	render to selection buffer using the selected shape as reference, then apply
**	sobel filter over main buffer
*/
t_bool	set_selection(t_scene *scene);

/*
**	BONUS:
**	(Sphere) texturing / Bump mapping
**	EXTRA BONUS: all objects + gloss/reflection/specular/roughness
**	Using texcoords, we can apply not only a color map texture, but we are
**	able to use a 3rd party normal map and translate it's UV colors into
**	a unit length vector which we rotate along the surface normal, which
**	simulates "fake" lighting being projected onto a surface
**	---
**	Classic ray tracing textures include:
**	Normals - surface imperfections
**	Gloss - determines the smoothness of the surface, meaning the exponent of
**	the spot highlight created in s_shaded.
**	Reflection - the blending color for all reflected rays
**	Specularity - the amount of light the gloss exponent generates, mixed with
**	diffuse
**	---
**	Path tracing textures include classic tracing textures and:
**	Roughness - scattering of a reflected ray, roughness maps are the opposite
**	of gloss maps, the difference is the inversion of color.
**	Normals are incorrect according to the real BRDF model, however this is best
**	left for the user, as certain normal maps combined with the right roughness
**	still manage to simulate a correct BRDF. Microfacets are not dealt with.
*/
void	set_textures(t_hitrecord *rec, t_bool brdf);
void	set_diffuse(t_hitrecord *rec, t_real u, t_real v);
void	set_normals(t_hitrecord *rec, t_real u, t_real v);
void	set_gloss(t_hitrecord *rec, t_real u, t_real v);
void	set_reflection(t_hitrecord *rec, t_real u, t_real v);
void	set_specularity(t_hitrecord *rec, t_real u, t_real v);
void	set_roughness(t_hitrecord *rec, t_real u, t_real v);
void	set_emission(t_hitrecord *rec, t_real u, t_real v);
void	free_textures(t_scene *scene, t_texture **list);

# endif
#endif
