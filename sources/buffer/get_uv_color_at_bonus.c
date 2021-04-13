/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_uv_color_at_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/25 16:05:51 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/13 11:32:11 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <buffer.h>
# include <color.h>
# include <math.h>
# include <utils.h>

/*
**	bilinear interpolation for images, return interpolated color.
*/

t_rgb	filter_bilinear(t_buffer *buf, t_real u, t_real v)
{
	int		u_[2];
	int		v_[2];
	double	u_bias;
	double	v_bias;
	t_rgb	color[6];

	u_[0] = floor(u);
	u_[1] = (int)setcnd(ceil(u) == buf->width, 0, ceil(u));
	v_[0] = floor(v);
	v_[1] = (int)setcnd(ceil(v) == buf->height, 0, ceil(v));
	u_bias = setcnd(floor(u) == 0, u, fmod(u, floor(u)));
	v_bias = setcnd(floor(v) == 0, v, fmod(v, floor(v)));
	color[0] = get_color_at(buf, u_[0], v_[0]);
	color[1] = get_color_at(buf, u_[1], v_[0]);
	color[2] = get_color_at(buf, u_[0], v_[1]);
	color[3] = get_color_at(buf, u_[1], v_[1]);
	color[4] = vec3_add(vec3_mult_s(color[0], 1 - u_bias),
			vec3_mult_s(color[1], u_bias));
	color[5] = vec3_add(vec3_mult_s(color[2], 1 - u_bias),
			vec3_mult_s(color[3], u_bias));
	return (vec3_add(vec3_mult_s(color[4], 1 - v_bias),
			vec3_mult_s(color[5], v_bias)));
}

t_rgb	get_uv_color_at(t_buffer *buf, t_real u, t_real v)
{
	t_rgb	gammac;

	u *= buf->width;
	v *= buf->height;
	gammac = filter_bilinear(buf, u, v);
	if (buf->de_gamma)
	{
		gammac.x = pow(gammac.x, 2.2);
		gammac.y = pow(gammac.y, 2.2);
		gammac.z = pow(gammac.z, 2.2);
	}
	return (gammac);
}

#endif
