/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unlit.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 16:42:26 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:42:46 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>

t_rgb	s_unlit(t_scene *scene, t_hitrecord *rec)
{	
	(void)scene;
	return (rec->color);
}
