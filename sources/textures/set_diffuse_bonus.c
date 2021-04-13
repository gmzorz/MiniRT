/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_diffuse_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/28 12:19:34 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:17:21 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <scene.h>
# include <unistd.h>
# include <buffer_bonus.h>

void	set_diffuse(t_hitrecord *rec, t_real u, t_real v)
{
	if (rec->ref->mat.t_diffuse.map == NULL)
		rec->color = rec->ref->mat.diffuse;
	else
		rec->color = get_uv_color_at(rec->ref->mat.t_diffuse.map, u, v);
}

#endif
