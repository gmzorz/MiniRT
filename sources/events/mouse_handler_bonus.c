/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mouse_handler_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/12 12:27:26 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/13 11:51:41 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <events.h>
# include <jump_tables.h>

int	mouse_handle(int button, int u, int v, t_scene *scene)
{
	int		idx;

	idx = 0;
	scene->u = u;
	scene->v = v;
	if (scene->viewport == shaded)
		scene->viewport = flat;
	while (!jump_btn(scene, button, &idx))
		idx += 1;
	if (idx == -1)
		return (1);
	if (update(scene) == false)
		free_and_exit(scene);
	return (1);
}

#endif
