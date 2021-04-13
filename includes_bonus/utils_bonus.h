/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_bonus.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 14:13:51 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/07 16:03:21 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H
# include <alias.h>

/*
**	Initialize the random seed based on time
**	Always do this before using rt_rand()
*/
void	rand_init(void);

/*
**	Return a random double in range [0.0 ... 1.0]
*/
t_real	rt_rand(void);

/*
**	Return a random unit double in range [-1.0 ... 1.0]
*/
t_real	rt_urand(void);

/*
**	Verify whether path has quotation marks
**	if so, remove marks/parse into new string
*/
char	*trim_path(char **line);

/*
**	return average (greyscale) value of each t_rgb element
*/
t_real	greyscale(t_rgb color);

/*
**	Tile/mirror the UV coordinate accordingly
*/
t_real	set_tiling(const t_real uv, const t_real scale);

#endif
