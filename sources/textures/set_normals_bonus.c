/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_normals_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/28 12:13:07 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 23:19:29 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <scene.h>
# include <buffer_bonus.h>
# include <math.h>

static t_vec3	vec3_rotx(t_vec3 vec, double angle)
{
	t_vec3	pitch;

	pitch.x = vec.x * cos(angle) + vec.z * sin(angle);
	pitch.y = vec.y;
	pitch.z = vec.x * -sin(angle) + vec.z * cos(angle);
	return (pitch);
}

static t_vec3	vec3_rotz(t_vec3 vec, double angle)
{
	t_vec3	roll;

	roll.x = vec.x;
	roll.y = vec.y * cos(angle) + vec.z * -sin(angle);
	roll.z = vec.y * sin(angle) + vec.z * cos(angle);
	return (roll);
}

static void	wave_apply(t_hitrecord *rec, t_real u, t_real v)
{
	t_vec3	basenml;
	t_mat4	tbn;
	t_vec3	span[2];
	t_wave	wv;

	wv = rec->ref->mat.wave;
	if (!(wv.using.u || wv.using.v))
		return ;
	basenml = (t_vec3){0.0, 0.0, 1.0};
	span[0] = vec3_unit(vec3_cross(rec->normal, vec3_id(ID_Y)));
	if (vec3_cmp(span[0], vec3_zero()))
		span[0] = vec3_unit(vec3_cross(rec->normal, vec3_id(ID_Z)));
	span[1] = vec3_unit(vec3_cross(rec->normal, span[0]));
	tbn = mat4(vec3_zero(), rec->normal, span[0], span[1]);
	if (wv.using.u)
		basenml = vec3_rotx(basenml, wv.amp * sin(u * PI_2 * wv.freq));
	if (wv.using.v)
		basenml = vec3_rotz(basenml, wv.amp * sin(v * PI_2 * wv.freq));
	rec->normal = vec3_unit(mat4_mult_dir(tbn, basenml));
}

void	set_normals(t_hitrecord *rec, t_real u, t_real v)
{
	t_mat4		tbn;
	t_vec3		tangent;
	t_vec3		bitangent;
	t_rgb		getc;

	if (rec->ref->mat.t_normal.map != NULL)
	{
		tangent = vec3_cross(rec->normal, vec3_id(ID_Y));
		if (vec3_cmp(tangent, vec3_zero()))
			tangent = vec3_unit(vec3_cross(rec->normal, vec3_id(ID_Z)));
		bitangent = vec3_unit(vec3_cross(rec->normal, tangent));
		tbn = mat4(vec3_zero(), rec->normal, bitangent, tangent);
		getc = get_uv_color_at(rec->ref->mat.t_normal.map, u, v);
		rec->normal = vec3_unit(mat4_mult_dir(tbn, vec3_sub_s(vec3_div_s(
							getc, 0.5), 1)));
	}
	wave_apply(rec, u, v);
}

#endif
