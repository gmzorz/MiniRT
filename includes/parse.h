/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 15:00:55 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/13 00:06:45 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# if IS_BONUS == 1
#  include <parse_bonus.h>
# endif
# include <alias.h>
# include <scene.h>
# define RT_SAVE_SS "--save"

t_bool	parse_to_scene(t_scene *scene, const char *rt_file);
t_bool	parse_failure(void *freeable);
char	*parse_id(char **line);
t_bool	parse_real(char **line, t_real *in);
t_bool	parse_unit(char **line, t_real *in, t_bool sign);
t_bool	parse_int(char **line, int *in);
t_bool	parse_unused(char **line);
t_bool	parse_eol(char **line);
t_bool	parse_skip(char **line, const char *delim, int skip_count);
t_bool	parse_vector(char **line, t_vec3 *vector);
t_bool	parse_normal(char **line, t_vec3 *normal);
t_bool	parse_color(char **line, t_rgb *color);
t_bool	parse_material(t_scene *scene, char **line, t_material *mat);
t_bool	parse_resolution(t_scene *scene, char **line);
t_bool	parse_ambience(t_scene *scene, char **line);
t_bool	parse_camera(t_scene *scene, char **line);
t_bool	parse_light(t_scene *scene, char **line);
t_bool	parse_shape(t_scene *scene, char **line);
t_bool	parse_light(t_scene *scene, char **line);
t_bool	parse_sphere(t_scene *scene, char **line);
t_bool	parse_plane(t_scene *scene, char **line);
t_bool	parse_square(t_scene *scene, char **line);
t_bool	parse_cylinder(t_scene *scene, char **line);
t_bool	parse_triangle(t_scene *scene, char **line);
t_bool	shape_push_back(t_shapes **list, void *shape, t_material mat,
			t_shapetype type);
t_bool	light_push_back(t_lights **list, t_lights *light);
t_bool	cam_push_back(t_camlist **list, t_camera *cam, int id);

#endif
