/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_sphere.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/11 15:35:00 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:42:08 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <error.h>
#include <libft.h>
#include <math.h>

t_bool	parse_sphere(t_scene *scene, char **line)
{
	t_sphere	*sphere;
	t_material	mat;

	sphere = (t_sphere *)ft_calloc(1, sizeof(t_sphere));
	if (sphere == NULL)
		return (error_msg(ERR_ALLOC_SPHERE));
	if (!parse_vector(line, &sphere->origin)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_real(line, &sphere->radius)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_material(scene, line, &mat)
		|| !parse_eol(line))
		return (parse_failure(sphere));
	sphere->radius = fabs(sphere->radius * 0.5);
	return (shape_push_back(&scene->shapes, sphere, mat, sh_sphere));
}
