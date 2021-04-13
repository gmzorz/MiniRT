/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_bonus.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/10 10:37:28 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:40:16 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <jump_tables.h>
# include <events.h>

t_bool	jump_key(t_scene *scene, int key)
{
	int					idx;
	static t_jump_key	jk[] = {
		{Esc, free_and_exit}, {Enter, render_scene},
		{Space, render_brdf}, {Dot, next_cam}, {Comma, prev_cam},
		{L, yaw_right}, {J, yaw_left}, {I, pitch_up}, {K, pitch_down},
		{U, roll_left}, {O, roll_right}, {A, move_left}, {D, move_right},
		{W, move_forward}, {S, move_back}, {Q, move_down}, {E, move_up},
		{One, render_flat}, {Two, render_unlit}, {Four, render_normals},
		{Five, render_units}, {Six, render_uvs}, {Seven, render_dof},
		{Three, render_aabb}, {Shift, take_screenshot}, {R, sh_trans_set_rot},
		{T, sh_trans_set_pos}, {X, sh_set_axis_x}, {Y, sh_set_axis_y},
		{Z, sh_set_axis_z}, {Plus, fov_increase}, {Minus, fov_decrease},
		{Up, sh_translate_up}, {Down, sh_translate_dn},
		{NOKEY, NULL}
	};

	idx = 0;
	if (scene->viewport == brdf)
		scene->viewport = flat;
	while (jk[idx].key != NOKEY && key != jk[idx].key)
		idx += 1;
	if (jk[idx].key == NOKEY)
		return (false);
	scene->do_update = true;
	return (jk[idx].press(scene));
}

#endif
