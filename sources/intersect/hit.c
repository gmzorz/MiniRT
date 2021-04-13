/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hit.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/18 13:53:01 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:43:08 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>

t_bool	hit(t_shapes *shape, t_hitrecord *rec, t_real distance)
{
	rec->ref = shape;
	rec->distance = distance;
	return (true);
}
