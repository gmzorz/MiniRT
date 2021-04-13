/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_emission_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/28 12:19:34 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 17:28:02 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <scene.h>
# include <buffer_bonus.h>
# include <unistd.h>

void	set_emission(t_hitrecord *rec, t_real u, t_real v)
{
	if (rec->ref->mat.t_emission.map == NULL)
		rec->emission = rec->ref->mat.emission;
	else
		rec->emission = vec3_mult_s(get_uv_color_at(
					rec->ref->mat.t_emission.map, u, v), 10);
}

#endif
