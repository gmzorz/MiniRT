/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   events_bonus.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/10 10:39:01 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/13 12:19:06 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_BONUS_H
# define EVENTS_BONUS_H
# include <scene.h>
# if IS_BONUS == 1
#  define SHAPE_MOVE 0.5
#  define SHAPE_ROT 18
#  define DOF_DIST_SCALE 0.25
#  define SS_DIR "screenshots/"
#  define SS_DEF "screenshot.bmp"
#  define SS_DIR_CREATE "Creating directory for screenshots.."
#  define SET_AXIS_X "Selection: translation axis [X]"
#  define SET_AXIS_Y "Selection: translation axis [Y]"
#  define SET_AXIS_Z "Selection: translation axis [Z]"
#  define SET_TRANS_MODE_T "Selection: translation mode [Translate]"
#  define SET_TRANS_MODE_R "Selection: translation mode [Rotate]"
#  define SH_DESELECT "Selection cleared"
#  define SH_SELECT "Selected "

typedef enum e_btn
{
	Mouse1 = 1,
	Mouse2 = 2,
	Mouse3 = 3,
	Mouse4 = 4,
	Mouse5 = 5,
	NOBTN = -1
}	t_btn;

/*
**	parse mouse input and redirect to event
*/
int		mouse_handle(int button, int u, int v, t_scene *scene);

/*
**	Camera movement
*/

t_bool	move_down(t_scene *scene);
t_bool	move_up(t_scene *scene);
t_bool	move_right(t_scene *scene);
t_bool	move_left(t_scene *scene);
t_bool	move_forward(t_scene *scene);
t_bool	move_back(t_scene *scene);
t_bool	yaw_right(t_scene *scene);
t_bool	yaw_left(t_scene *scene);
t_bool	pitch_up(t_scene *scene);
t_bool	pitch_down(t_scene *scene);
t_bool	roll_right(t_scene *scene);
t_bool	roll_left(t_scene *scene);
t_bool	dof_adjust_dn(t_scene *scene);
t_bool	dof_adjust_up(t_scene *scene);
t_bool	fov_increase(t_scene *scene);
t_bool	fov_decrease(t_scene *scene);

/*
**	Viewport debugging
*/

t_bool	render_units(t_scene *scene);
t_bool	render_normals(t_scene *scene);
t_bool	render_uvs(t_scene *scene);
t_bool	render_brdf(t_scene *scene);
t_bool	render_dof(t_scene *scene);
t_bool	take_screenshot(t_scene *scene);

/*
**	Mouse actions
*/

t_bool	select_shape(t_scene *scene);
t_bool	sh_deselect(t_scene *scene);

/*
**	Init translation type (position offset, rotation, scale)
**	and axis
*/

t_bool	sh_trans_set_rot(t_scene *scene);
t_bool	sh_trans_set_pos(t_scene *scene);
t_bool	sh_trans_set_scl(t_scene *scene);
t_bool	sh_set_axis_x(t_scene *scene);
t_bool	sh_set_axis_y(t_scene *scene);
t_bool	sh_set_axis_z(t_scene *scene);

/*
**	Translate shape over a single axis using the mouse wheel
*/

t_bool	sh_translate_up(t_scene *scene);
t_bool	sh_translate_dn(t_scene *scene);

/*
**	Translation tools
*/

t_bool	cube_translate(t_scene *scene);
t_bool	plane_translate(t_scene *scene);
t_bool	sphere_translate(t_scene *scene);
t_bool	square_translate(t_scene *scene);
t_bool	cylinder_translate(t_scene *scene);
t_bool	disk_translate(t_scene *scene);
t_bool	triangle_translate(t_scene *scene);
t_bool	pyramid_translate(t_scene *scene);
t_bool	trimesh_translate(t_scene *scene);
t_bool	translate(t_scene *scene, t_vec3 *vec);
t_bool	rotate(t_scene *scene, t_mat4 *mat);

# endif
#endif
