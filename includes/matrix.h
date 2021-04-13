/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/28 12:50:28 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/13 13:00:31 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H
# include <vector.h>

typedef enum e_getmat4elem
{
	m_origin,
	m_forward,
	m_backward,
	m_right,
	m_left,
	m_up,
	m_down
}	t_getmat4elem;

typedef struct s_mat4
{
	double			data[4][4];
}	t_mat4;

/*
**	Initialize a new 4x4 matrix
*/
t_mat4	mat4(t_vec3 origin, t_vec3 forward, t_vec3 right,
			t_vec3 up);

/*
**	Retrieve vectors within matrix
**	mat4_get(matrix, type)
**	type specifiers:
**		m_right, m_up, m_forward, m_origin
*/
t_vec3	mat4_get(t_mat4 matrix, t_getmat4elem get);

/*
**	Create a new matrix containing a set of cartesian coordinates that define
**	the axes of the camera based on its origin and direction
*/
t_mat4	mat4_lookat(t_vec3 origin, t_vec3 look_at);

/*
**	Translate the matrix <matrix> using vector addition <add>
*/
t_mat4	mat4_add_vec(t_mat4 matrix, t_vec3 add);

/*
**	Translate the matrix <matrix> using vector subtraction <sub>
*/
t_mat4	mat4_sub_vec(t_mat4 matrix, t_vec3 sub);

/*
**	Multiply matrix <src> with matrix <mult>
*/
t_mat4	mat4_mult(t_mat4 src, t_mat4 mult);

/*
**	Multiply each point3 vector within matrix <matrix> with vector <mult>
**	and return as single new vector
*/
t_vec3	mat4_mult_dir(t_mat4 matrix, t_vec3 mult);

/*
**	Initialize new identity matrix containing:
**	 Right vector			(1.0, 0.0, 0.0)
**	 Up vector				(0.0, 1.0, 0.0)
**	 Forward vector			(0.0, 0.0, 1.0)
**	 (1)Origin vector		(0.0, 0.0, 0.0)
**
**	(1) - Arbitrary
*/
t_mat4	mat4_identity(void);

/*
**	Rotate matrix <matrix> around its Y axis in <degrees>
*/
t_mat4	mat4_roty(const t_real degrees);

/*
**	Rotate matrix <matrix> around its X axis in <degrees>
*/
t_mat4	mat4_rotx(const t_real degrees);

/*
**	Rotate matrix <matrix> around its Z axis in <degrees>
*/
t_mat4	mat4_rotz(const t_real degrees);

/*
**	Rotate matrix <matrix> around its XYZ axes using degrees defined by <rotate>
*/
t_mat4	mat4_rotate(const t_vec3 rotate);

/*
**	Rotate matrix <matrix> around its XYZ axes using degrees defined by <rotate>
**	around vector <point>
*/
t_mat4	mat4_rota(t_mat4 src, t_vec3 point, t_vec3 angle);

#endif
