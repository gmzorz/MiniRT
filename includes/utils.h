/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 14:13:51 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/13 13:31:59 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <alias.h>
# include <color.h>
# if IS_BONUS == 1
#  include <utils_bonus.h>
# endif
# define BMP_HEADER_SIZE 14
# define DIB_SIZE 40
# define PIXEL_SIZE 4
# define BMP_PIXEL_OFFSET 54

void		print_welcome(void);
void		write_bin(t_bool *check, int fd, void *value, int size);
void		write_def(t_bool *check, int fd, void *value, int size);
t_real		setcnd(int condition, t_real pos, t_real neg);

/*
**	Clamp value between two real numbers
*/
t_real		clamp(t_real in, t_real min, t_real max);

/*
**	pow_2() is seemingly faster than using the pow() function in <math.h>
*/
t_real		pow_2(t_real number);

/*
**	Calculating point of intersection
**	 P = Ro + Rd * t
*/
t_vec3		get_point(t_vec3 ro, t_vec3 rd, t_real t);

/*
**	Progress bar
*/
void		scene_completion(t_real *completion, t_real add);

#endif
