/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_bonus.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 15:00:55 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/09 11:11:01 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_BONUS_H
# define PARSE_BONUS_H
# if IS_BONUS == 1
#  include <alias.h>
#  include <scene.h>
#  include <color.h>
#  define MAT_FLAG			"-mat"
#  define DOF_FLAG			"-dof"
#  define DIF_ID			"diffuse"
#  define SPC_ID			"specular"
#  define GLS_ID			"gloss"
#  define RFL_ID			"reflection"
#  define EMS_ID			"emission"
#  define RGH_ID			"roughness"
#  define DIF_MAP_ID		"diffuse_map"
#  define NML_MAP_ID		"normal_map"
#  define SPC_MAP_ID		"specular_map"
#  define GLS_MAP_ID		"gloss_map"
#  define RFL_MAP_ID		"reflection_map"
#  define EMS_MAP_ID		"emission_map"
#  define RGH_MAP_ID		"roughness_map"
#  define WAVE_ID			"wave"
#  define TEX_SIZE_X_ID		"scale_x"
#  define TEX_SIZE_Y_ID		"scale_y"
#  define XPM_SUFX		 	".xpm"
#  define VP_FULL			"full"
#  define VP_HALF			"half"
#  define VP_QUARTER		"quarter"

t_bool	parse_disk(t_scene *scene, char **line);
t_bool	parse_cylinder_cap(t_scene *scene, char **line);
t_bool	parse_light_parallel(t_scene *scene, char **line);
t_bool	parse_aa(t_scene *scene, char **line);
t_bool	parse_skybox(t_scene *scene, char **line);
t_bool	parse_tex(t_scene *scene, char **line, t_texture *tex);
t_bool	parse_brdf(t_scene *scene, char **line);
t_bool	parse_cube(t_scene *scene, char **line);
t_bool	parse_pyramid(t_scene *scene, char **line);
t_bool	parse_sun(t_scene *scene, char **line);
t_bool	parse_wfobj(t_scene *scene, char **line);
t_bool	parse_wfobj_vector(char **line, t_vertex *vertex, t_aabb *volume);
t_bool	wfobj_face_assign(char **line, t_trimesh *mesh, int idx);
void	wfobj_close_and_free(int fd, char *line);
void	wfobj_set_origin(t_trimesh *mesh);
t_bool	wfobj_error_free(t_trimesh *mesh, char *msg);
t_bool	parse_wave(char **line, t_wave *wave);
t_bool	parse_bool(char **line, t_bool *in);
t_bool	parse_threads(t_scene *scene, char **line);
t_bool	parse_viewport(t_scene *scene, char **line);

# endif
#endif
