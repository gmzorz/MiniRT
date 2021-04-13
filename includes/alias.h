/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   alias.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:14:32 by goosterl      #+#    #+#                 */
/*   Updated: 2020/12/02 14:08:12 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALIAS_H
# define ALIAS_H
# define M_EPSILON 1e-8
# define M_INFINITY 1.0e30f
# define COLOR_SIZE 8
# define DELIM_SPACE " \t\n\v\f\r"
# define DELIM_QUOT "\""
# define DELIM_COMMA ","
# define PI_2 6.28318531

/*
**	real number
*/
typedef double	t_real;

/*
**	boolean for return values
*/
typedef enum e_bool
{
	false = 0,
	true = 1
}	t_bool;

#endif
