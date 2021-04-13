/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   elements_bonus.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 14:22:22 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/07 23:20:05 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENTS_BONUS_H
# define ELEMENTS_BONUS_H
# if IS_BONUS == 1
#  include <alias.h>
#  include <color.h>
#  define DOF_SPHERICAL 1 
#  define DOF_ANAMORPHIC 2
#  define DOF_SHAPEMASK 0

/*
**	Depth of field parameters
**	 shape_type 	- Determine blur based on unit disc rather than square
**	 aperture	- Blur amount
**	 focal_dist	- distance to focal plane (in focus)
*/
typedef struct s_dof
{
	t_bool		enable;
	int			shape_type;
	t_real		aperture;
	t_real		focal_dist;
	t_vec3		focal_point;
	t_vec3		plane_normal;
	t_texture	shape;
}	t_dof;

typedef struct s_lights
{
	t_vec3		origin;
	t_real		intensity;
	t_rgb		color;
	t_vec3		normal;
	t_real		lp_bias;
	t_vec3		dir;
	t_real		dist;
	t_real		angle;
	void		*next;
}	t_lights;

typedef struct s_camera
{
	t_vec3		origin;
	t_vec3		normal;
	t_real		fov;
	t_real		view_range;
	t_mat4		world;
	t_dof		dof;
}	t_camera;

# endif
#endif