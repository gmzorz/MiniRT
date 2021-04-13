/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_bonus.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 15:23:10 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/02 14:12:32 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_BONUS_H
# define COLOR_BONUS_H
# if IS_BONUS == 1
#  include <vector.h>
#  include <buffer.h>
#  define RT_FREE_TEXTURES "Cleaning up textures"

typedef t_vec3	t_rgb;

/*
**	Texture(s) (list)
**	In t_scene, t_texture is used as a list of allocated buffers that can
**	be used as a lookup list. memory is vital so we do not use duplicate
**	buffers to store images. We create a buffer for each parsed texture,
**	but if the buffer already exists, the buffer should be referenced instead
*/
typedef struct s_texture
{
	char		*file;
	t_buffer	*map;
	t_real		blend;
	t_bool		ignore;
	void		*next;
}	t_texture;

typedef struct s_wave
{
	t_vec2		using;
	t_real		amp;
	t_real		freq;
	t_real		offset;
}	t_wave;

typedef struct s_material
{
	t_rgb		diffuse;
	t_rgb		specular;
	t_real		gloss;
	t_rgb		reflection;
	t_rgb		emission;
	t_real		roughness;
	t_wave		wave;
	t_texture	t_diffuse;
	t_texture	t_normal;
	t_texture	t_specular;
	t_texture	t_gloss;
	t_texture	t_roughness;
	t_texture	t_reflection;
	t_texture	t_emission;
	t_real		tex_size_x;
	t_real		tex_size_y;
}	t_material;

# endif
#endif
