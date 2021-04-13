/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   elements.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 14:26:32 by goosterl      #+#    #+#                 */
/*   Updated: 2021/03/25 13:26:32 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENTS_H
# define ELEMENTS_H
# include <alias.h>
# include <vector.h>
# include <matrix.h>
# include <color.h>
# if IS_BONUS == 1
#  include <elements_bonus.h>
# else

typedef struct s_lights
{
	t_vec3		origin;
	t_real		intensity;
	t_rgb		color;
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
}	t_camera;

# endif

typedef struct s_camlist
{
	int			id;
	t_camera	*cam;
	void		*next;
}	t_camlist;

#endif
