/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sobel_bonus.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/05 15:37:43 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 17:29:45 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <buffer.h>
# include <utils.h>
# include <filter.h>

static t_bool	mem_check_12(char *loc, const char *id)
{
	int			idx;
	t_bool		success;

	idx = 0;
	success = true;
	while (idx < 12 && success)
	{
		if (success && loc[idx] != id[idx])
			success = false;
		idx += 1;
	}
	return (success);
}

/*
**	Slightly faster check used for the selection outlines
**	not sure how to properly speed up a kernel convolution
*/

static t_bool	cells_are_empty(t_buffer *in, int u, int v)
{
	char		*loc[3];
	const char	miss[] = {
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
	const char	hit[] = {
		0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0x00};

	loc[0] = in->address + ((v - 1) * in->row_size + (u - 1) * 4);
	loc[1] = in->address + (v * in->row_size + (u - 1) * 4);
	loc[2] = in->address + ((v + 1) * in->row_size + (u - 1) * 4);
	return ((mem_check_12(loc[0], hit)
			&& mem_check_12(loc[1], hit)
			&& mem_check_12(loc[2], hit))
		|| (mem_check_12(loc[0], miss)
			&& mem_check_12(loc[1], miss)
			&& mem_check_12(loc[2], miss)));
	return (true);
}

static t_real	get_sobel(t_buffer *in, int u, int v)
{
	t_real		xy[2];
	t_real		get_col;
	t_vec2		kern;
	int			lt[2];

	kern.u = -1;
	kern.v = -1;
	xy[0] = 0;
	xy[1] = 0;
	while (kern.u <= 1)
	{
		while (kern.v <= 1)
		{
			lt[0] = clamp(kern.u + u, 0, in->width - 1);
			lt[1] = clamp(kern.v + v, 0, in->height - 1);
			get_col = greyscale(get_color_at(in, lt[0], lt[1]));
			xy[0] += get_col * sobel3x3(kern.u + 1, kern.v + 1, 1);
			xy[1] += get_col * sobel3x3(kern.u + 1, kern.v + 1, 0);
			kern.v += 1;
		}
		kern.v = -1;
		kern.u += 1;
	}
	return (sobel_sum(xy[0], xy[1]));
}

t_bool	f_sobel(t_buffer *in, t_buffer *out, t_rgb col)
{
	t_real		aggr;
	t_vec2		vp;

	vp = (t_vec2){0.0, 0.0};
	while (vp.u < in->width)
	{
		while (vp.v < in->height)
		{
			if (!cells_are_empty(in, vp.u, vp.v))
			{
				aggr = clamp(get_sobel(in, vp.u, vp.v), 0, 1);
				if (aggr > 0)
					write_color_at(out, vp.u, vp.v, col);
			}
			vp.v += 1;
		}
		vp.v = 0;
		vp.u += 1;
	}
	return (true);
}

#endif
