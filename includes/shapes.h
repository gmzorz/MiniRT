/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shapes.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 14:29:43 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/02 11:03:22 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H
# if IS_BONUS == 1
#  include <shapes_bonus.h>
# endif
# include <vector.h>
# include <color.h>
# if IS_BONUS == 0

/*
**	Shape types, required for jump table in <jump_tables.h>
*/
typedef enum e_shapetype
{
	sh_sphere,
	sh_plane,
	sh_cylinder,
	sh_square,
	sh_triangle,
	sh_noshape
}	t_shapetype;

/*
**	axis aligned bounding box
*/
typedef struct s_aabb
{
	t_vec3		min;
	t_vec3		max;
	t_vec3		centroid;
	t_bool		using;
}	t_aabb;

typedef struct s_shapes
{
	void		*shape;
	t_shapetype	type;
	t_material	mat;
	t_aabb		volume;
	t_bool		construct;
	void		*next;
}	t_shapes;

# endif

/*
**	Sphere variables
**	 t			- Distance to point perpendicular to sphere center
**	 p			- Point perpendicular to sphere center
**	 y			- Distance from p to sphere center
**	 x			- Distance from p to root
**	 t1			- Distance to first point of intersection
**	 t2			- Distance to second point of intersection
*/
typedef struct s_sphere_vars
{
	t_real		t;
	t_vec3		p;
	t_real		y;
	t_real		x;
	t_real		t1;
	t_real		t2;
}	t_sphere_vars;

# if IS_BONUS == 0

typedef struct s_sphere
{
	t_vec3		origin;
	t_real		radius;
}	t_sphere;

# endif

/*
**	Plane variables
**	 pl			- (ray.dir • plane.normal) parallel check, miss if ~0
**	 p			- distance from ray.origin to plane.origin
**	 t			- distance to plane
*/
typedef struct s_plane_vars
{
	t_real		pl;
	t_vec3		p;
	t_real		t;
}	t_plane_vars;

# if IS_BONUS == 0

typedef struct s_plane
{
	t_vec3		origin;
	t_vec3		normal;
}	t_plane;

typedef struct s_square
{
	t_vec3		origin;
	t_vec3		normal;
	t_vec3		span_a;
	t_vec3		span_b;
	t_real		size;
}	t_square;

# endif

/*
**	Square variables
**	 pl			- (ray.dir • plane.normal) parallel check, miss if ~0
**	 p			- distance from ray.origin to plane.origin
**	 t			- distance to plane
**	 ab			- (arbitrary) span vector aka "Right"
**	 bc			- (arbitrary) span vector aka "Forward"
**	 point		- point on plane (see get_point())
**	 u			- span length (Right)
**	 v			- span length (forward)
*/
typedef struct s_square_vars
{
	t_real		pl;
	t_vec3		p;
	t_real		t;
	t_vec3		diff;
	t_vec3		point;
	t_real		u;
	t_real		v;
}	t_square_vars;

/*
**	Cylinder variables
**	 h			- height offset to top and bottom center
**	 a			- top center
**	 b			- bottom center
**	 ab			- distance between top and bottom
**	 ao			- distance between top and ray origin
**	 v1			- cross product between ao and ab
**	 v2			- cross product between ray dir and ab
*/
typedef struct s_cylinder_vars
{
	t_vec3		origin;
	t_vec3		dir;
	t_vec3		focal;
	t_real		a;
	t_real		a_2;
	t_real		b;
	t_real		c;
	t_real		d;
	t_real		d_sqr;
	t_bool		inside;
}	t_cylinder_vars;

# if IS_BONUS == 0

typedef struct s_cylinder
{
	t_vec3		origin;
	t_vec3		top;
	t_vec3		bottom;
	t_vec3		diff;
	t_vec3		normal;
	t_real		radius;
	t_real		height;
	t_real		height_d2;
	t_vec3		half_height;
}	t_cylinder;

/*
**	Triangle variables
**	 pl			- (ray.dir • plane.normal) parallel check, miss if ~0
**	 
*/
typedef struct s_triangle_vars
{
	t_real		pl;
	t_real		d;
	t_real		t;
	t_vec3		p;
	t_vec3		test[3];
}	t_triangle_vars;

typedef struct s_triangle
{
	t_vec3		vert[3];
	t_vec3		edge[3];
	t_vec3		normal;
	t_real		traverse;
}	t_triangle;

# endif
#endif