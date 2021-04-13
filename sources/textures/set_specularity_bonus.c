/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_specularity_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/28 13:16:47 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:18:00 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <scene.h>
# include <buffer_bonus.h>
# include <unistd.h>

void	set_specularity(t_hitrecord *rec, t_real u, t_real v)
{
	if (rec->ref->mat.t_specular.map != NULL)
		rec->specular = get_uv_color_at(rec->ref->mat.t_specular.map, u, v);
	else
		rec->specular = rec->ref->mat.specular;
}

#endif
