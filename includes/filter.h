/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filter.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/04 12:19:41 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/06 15:18:23 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILTER_H
# define FILTER_H
# include <buffer.h>
# include <color.h>

t_bool	f_sobel(t_buffer *in, t_buffer *out, t_rgb col);
t_real	sobel5x5(int idx1, int idx2, int xy);
t_real	sobel3x3(int idx1, int idx2, int xy);
t_rgb	sobel_sum3(t_rgb x, t_rgb y);
t_real	sobel_sum(t_real x, t_real y);

#endif