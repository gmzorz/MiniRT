/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:14:24 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 23:20:28 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include <alias.h>
# define ID_X 0
# define ID_Y 1
# define ID_Z 2

typedef struct s_vec3
{
	t_real		x;
	t_real		y;
	t_real		z;
}				t_vec3;

typedef struct s_vec2
{
	t_real		u;
	t_real		v;
}				t_vec2;

/*
**	Vector3 operators (using vec3 or scalars) and utils
*/

t_vec3	vec3_zero(void);
t_vec3	vec3_add(const t_vec3 one, const t_vec3 two);
t_vec3	vec3_add_s(const t_vec3 one, const t_real two);
t_vec3	vec3_sub(const t_vec3 one, const t_vec3 two);
t_vec3	vec3_sub_s(const t_vec3 one, const t_real two);
t_vec3	vec3_mult(const t_vec3 one, const t_vec3 two);
t_vec3	vec3_mult_s(const t_vec3 one, const t_real two);
t_vec3	vec3_div(const t_vec3 one, const t_vec3 two);
t_vec3	vec3_div_s(const t_vec3 one, const t_real two);
t_bool	vec3_cmp(const t_vec3 one, const t_vec3 two);
t_bool	vec3_cmp_s(const t_vec3 one, const t_real two);
t_bool	vec3_grt(const t_vec3 vector, const t_real number);
t_bool	vec3_lss(const t_vec3 vector, const t_real number);
t_vec3	vec3_abs(const t_vec3 vector);
t_vec3	vec3_clamp(t_vec3 in, const t_real min, const t_real max);
t_vec3	vec3_negate(const t_vec3 in);
t_vec3	vec3_avg(const t_vec3 one, const t_vec3 two);
t_vec3	vec3_id(const int id);

/*
**	Reflect a vector <vec> along vector <normal>
*/
t_vec3	vec3_reflect(const t_vec3 vec, const t_vec3 normal);

/*
**	Negated reflection of vector <vec> along vector <normal>
*/
t_vec3	vec3_bounce(const t_vec3 vec, const t_vec3 normal);

/*
**	Vector3 math: Cross product
**	Generates a new vector3 struct that lies (in world space) perpendicular
**	to the area of the two given vectors (right & forward, arbitrarily)
**	- return: 
*/
t_vec3	vec3_cross(const t_vec3 right, const t_vec3 forward);

/*
**	Vector3 math: Dot product
**	Generates a scalar value indicating the difference between two vectors
**	by multiplying both vectors and adding up all values
*/
t_real	vec3_dot(const t_vec3 one, const t_vec3 two);

/*
**	Vector3 math: normalization / unit vector
**	Normalizing a vector results in a vector with 1 as length/magnitude
**	This can be useful for vector scaling and usage of surface normals
**	Normalized vectors can also be described as unit vectors
*/
t_vec3	vec3_unit(const t_vec3 vector);

/*
**	Vector3 math: magnitude / length
**	Magnitude determines the length of the a vector from origin (0,0,0)
*/
t_real	vec3_mag(const t_vec3 vector);

/*
**	Generate a local coordinate system based on normal <up>
*/
void	vec3_local_coords(const t_vec3 up, t_vec3 *fw, t_vec3 *rt);

#endif
