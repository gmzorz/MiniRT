/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_material.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/22 14:59:06 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:41:11 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 0
# include <parse.h>

t_bool	parse_material(t_scene *scene, char **line, t_material *mat)
{
	(void)scene;
	if (!parse_color(line, &mat->diffuse))
		return (false);
	return (true);
}

#endif
