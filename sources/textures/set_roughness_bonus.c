/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_roughness_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/28 13:16:06 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:18:21 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <scene.h>
# include <buffer_bonus.h>
# include <unistd.h>
# include <utils.h>

/*
**	Side note, gloss is the same as roughness, just inverted
*/

void	set_roughness(t_hitrecord *rec, t_real u, t_real v)
{
	if (rec->ref->mat.t_roughness.map != NULL)
		rec->roughness = greyscale(
				get_uv_color_at(rec->ref->mat.t_roughness.map, u, v));
	else
		rec->roughness = rec->ref->mat.roughness;
}

#endif
