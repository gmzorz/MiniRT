/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tiling_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/25 17:21:40 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:57:36 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <alias.h>
# include <math.h>

t_real	set_tiling(const t_real uv, const t_real scale)
{
	t_real		out;

	out = uv;
	if (fabs(out) > 1)
		out = fmod(out, scale) / scale;
	else
	{
		if (scale < 1)
			out = fmod(out / scale, 1);
		else
			out /= scale;
	}
	if (out < 0)
		out = 1 - fabs(out);
	return (out);
}

#endif
