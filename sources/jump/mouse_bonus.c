/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mouse_bonus.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/10 10:37:28 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:40:50 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <jump_tables.h>
# include <events.h>

t_bool	jump_btn(t_scene *scene, int btn, int *idx)
{
	static t_jump_btn	jb[] = {
		{Mouse1, select_shape},
		{Mouse2, sh_deselect},
		{Mouse4, dof_adjust_up},
		{Mouse5, dof_adjust_dn},
		{NOBTN, NULL}
	};

	if (scene->viewport == brdf)
		scene->viewport = flat;
	scene->do_update = false;
	if (jb[*idx].btn == NOBTN)
	{
		*idx = -1;
		return (true);
	}
	if (btn == jb[*idx].btn)
		return (jb[*idx].press(scene));
	return (false);
}

#endif
