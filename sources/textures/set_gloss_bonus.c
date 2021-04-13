/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_gloss_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/28 14:54:09 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:16:42 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <scene.h>
# include <buffer_bonus.h>
# include <unistd.h>
# include <utils.h>
# include <math.h>

/*
**	The gloss parameter ranges from 0.0 ... 1.0, this controls the exponent
**	So in order to get a logical value slider, we set g = 2^(i*10)
**	0.1 = 2
**	0.2 = 4
**	0.3 = 8....
**	if undefined, we take the medium (32)
*/

void	set_gloss(t_hitrecord *rec, t_real u, t_real v)
{
	if (rec->ref->mat.t_gloss.map != NULL)
	{
		rec->gloss = pow(2, greyscale(get_uv_color_at(
						rec->ref->mat.t_gloss.map, u, v)) * 10);
	}
	else if (rec->ref->mat.gloss)
		rec->gloss = pow(2, rec->ref->mat.gloss * 10);
	else
		rec->gloss = 32;
}

#endif