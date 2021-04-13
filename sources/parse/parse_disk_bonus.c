/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_disk_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/18 11:07:43 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:40:20 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <parse.h>
# include <libft.h>
# include <error.h>
# include <math.h>

t_bool	parse_disk(t_scene *scene, char **line)
{
	t_disk		*disk;
	t_material	mat;

	disk = (t_disk *)ft_calloc(1, sizeof(t_disk));
	if (disk == NULL)
		return (error_msg(ERR_ALLOC_DISK));
	if (!parse_vector(line, &disk->origin)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_normal(line, &disk->normal)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_real(line, &disk->radius)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_material(scene, line, &mat)
		|| !parse_eol(line))
		return (parse_failure(disk));
	disk->radius = fabs(disk->radius * 0.5);
	return (shape_push_back(&scene->shapes, disk, mat, sh_disk));
}

#endif
