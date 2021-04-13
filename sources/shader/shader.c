/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shader.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 16:37:17 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:42:43 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <jump_tables.h>

t_rgb	shade(t_scene *scene, t_hitrecord *rec)
{
	t_rgb	col;

	col = vec3_zero();
	jump_shader(scene, rec, &col);
	return (col);
}
