/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_reflection_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/28 13:16:06 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:17:31 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <scene.h>
# include <buffer_bonus.h>
# include <unistd.h>

void	set_reflection(t_hitrecord *rec, t_real u, t_real v)
{
	if (rec->ref->mat.t_reflection.map != NULL)
		rec->reflection = get_uv_color_at(rec->ref->mat.t_reflection.map, u, v);
	else
		rec->reflection = rec->ref->mat.reflection;
}

#endif
