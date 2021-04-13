/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shapes_bonus.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/13 14:27:38 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/08 12:04:19 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_BONUS_H
# define SHAPES_BONUS_H
# include <vector.h>
# include <alias.h>
# include <color.h>
# if IS_BONUS == 1

typedef enum e_shapetype
{
	sh_sphere,
	sh_plane,
	sh_cylinder,
	sh_square,
	sh_triangle,
	sh_disk,
	sh_cube,
	sh_pyramid,
	sh_trimesh,
	sh_noshape
}	t_shapetype;

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

typedef struct s_sphere
{
	t_vec3		origin;
	t_real		radius;
	t_vec3		normal;
}	t_sphere;

typedef struct s_triangle_vars
{
	t_real		pl;
	t_real		d;
	t_real		t;
	t_vec3		p;
	t_real		u;
	t_real		v;
}	t_triangle_vars;

typedef struct s_triangle
{
	t_vec3		vert[3];
	t_vec3		edge[3];
	t_vec3		normal;
	t_vec3		vert_normal[3];
	t_real		traverse;
	t_real		dot_aa;
	t_real		dot_ab;
	t_real		dot_bb;
	t_real		denom;
}	t_triangle;

typedef struct s_vertex
{
	t_vec3		point;
	t_vec3		normal;
}	t_vertex;

typedef struct s_meshtri
{
	int			idx[3];
	t_vertex	*vert[3];
	t_vec3		edge[3];
	t_aabb		volume;
	t_vec3		normal;
	t_real		traverse;
	t_real		dot_aa;
	t_real		dot_ab;
	t_real		dot_bb;
	t_real		denom;
}	t_meshtri;

typedef struct s_bvhnode
{
	struct s_bvhnode	*branch;
	int					depth;
	t_meshtri			**faces;
	int					size;
	t_aabb				volume;
}	t_bvhnode;

typedef struct s_trimesh
{
	t_vertex	*vert;
	t_meshtri	*face;
	t_bvhnode	root;
	t_aabb		volume;
	int			verts;
	int			faces;
	t_vec3		centroid;
	t_vec3		origin;
	t_vec3		normal;
	t_vec3		span_a;
	t_vec3		span_b;
	t_bool		construct;
}	t_trimesh;

typedef struct s_square
{
	t_vec3		origin;
	t_vec3		normal;
	t_vec3		span_a;
	t_vec3		span_b;
	t_real		size;
}	t_square;

typedef struct s_pyramid
{
	t_vec3		origin;
	t_vec3		normal;
	t_vec3		span_a;
	t_vec3		span_b;
	t_real		base_size;
	t_real		height;
	t_triangle	face[4];
	t_square	base;
}	t_pyramid;

typedef struct s_cube
{
	t_vec3		origin;
	t_vec3		normal;
	t_vec3		span_a;
	t_vec3		span_b;
	t_real		size;
	t_square	face[6];
}	t_cube;

typedef struct s_plane
{
	t_vec3		origin;
	t_vec3		normal;
	t_vec3		span_a;
	t_vec3		span_b;
}	t_plane;

typedef struct s_disk
{
	t_vec3		origin;
	t_vec3		span_a;
	t_vec3		span_b;
	t_vec3		normal;
	t_real		radius;
	t_bool		culling;
}	t_disk;

typedef struct s_cylinder
{
	t_vec3		origin;
	t_vec3		top;
	t_vec3		bottom;
	t_vec3		diff;
	t_vec3		normal;
	t_vec3		span_a;
	t_vec3		span_b;
	t_real		radius;
	t_real		height;
	t_real		height_d2;
	t_vec3		half_height;
	t_bool		capped;
	t_disk		upper;
	t_disk		lower;
}	t_cylinder;

void	free_trimesh(t_shapes *catch);
void	free_bvh_nodes(t_bvhnode *root);

# endif
#endif
