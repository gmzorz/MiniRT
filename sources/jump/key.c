/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/10 10:37:28 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:10:53 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 0
# include <jump_tables.h>
# include <events.h>
# include <unistd.h>

t_bool	jump_key(t_scene *scene, int key)
{
	int					idx;
	static t_jump_key	jk[] = {
		{Esc, free_and_exit},
		{One, render_flat},
		{Two, render_unlit},
		{Three, render_aabb},
		{Enter, render_scene},
		{Dot, next_cam},
		{Comma, prev_cam},
		{NOKEY, NULL}
	};

	idx = 0;
	while (jk[idx].key != NOKEY && key != jk[idx].key)
		idx += 1;
	if (jk[idx].key == NOKEY)
		return (false);
	return (jk[idx].press(scene));
}

#endif
