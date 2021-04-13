/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_material_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/20 16:38:16 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:35:09 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <get_next_line.h>
# include <fcntl.h>
# include <error.h>
# include <libft.h>
# include <parse.h>
# include <utils.h>
# include <init.h>

static t_bool	property_assign(const char *id, char **line,
	t_material *mat)
{
	if (ft_match(id, TEX_SIZE_X_ID))
		return (parse_real(line, &mat->tex_size_x));
	if (ft_match(id, TEX_SIZE_Y_ID))
		return (parse_real(line, &mat->tex_size_y));
	if (ft_match(id, DIF_ID))
		return (parse_color(line, &mat->diffuse));
	if (ft_match(id, SPC_ID))
		return (parse_color(line, &mat->specular));
	if (ft_match(id, EMS_ID))
		return (parse_vector(line, &mat->emission));
	if (ft_match(id, GLS_ID))
		return (parse_unit(line, &mat->gloss, false));
	if (ft_match(id, RGH_ID))
		return (parse_unit(line, &mat->roughness, false));
	if (ft_match(id, RFL_ID))
		return (parse_color(line, &mat->reflection));
	if (ft_match(id, WAVE_ID))
		return (parse_wave(line, &mat->wave));
	else
		return (error_msg(ERR_MAT_PROP));
}

static t_bool	texture_assign(t_scene *scene, const char *id, char **line,
	t_material *mat)
{
	if (ft_match(id, DIF_MAP_ID))
		return (parse_tex(scene, line, &mat->t_diffuse));
	if (ft_match(id, NML_MAP_ID))
		return (parse_tex(scene, line, &mat->t_normal));
	if (ft_match(id, SPC_MAP_ID))
		return (parse_tex(scene, line, &mat->t_specular));
	if (ft_match(id, GLS_MAP_ID))
		return (parse_tex(scene, line, &mat->t_gloss));
	if (ft_match(id, RFL_MAP_ID))
		return (parse_tex(scene, line, &mat->t_reflection));
	if (ft_match(id, EMS_MAP_ID))
		return (parse_tex(scene, line, &mat->t_emission));
	if (ft_match(id, RGH_MAP_ID))
		return (parse_tex(scene, line, &mat->t_roughness));
	if (property_assign(id, line, mat))
		return (true);
	return (error_msg(ERR_MAT_PROP));
}

static t_bool	read_file(t_scene *scene, t_material *mat, t_fileinf inf)
{
	char		*id;

	inf.success = true;
	while (get_next_line(inf.fd, &inf.line) > 0)
	{
		inf.line_cpy = inf.line;
		id = parse_id(&inf.line);
		if (id)
		{
			if (!texture_assign(scene, id, &inf.line, mat)
				|| !parse_eol(&inf.line))
				inf.success = error_line(inf.line_cpy);
			free(id);
		}
		free(inf.line_cpy);
	}
	free(inf.line);
	close(inf.fd);
	return (inf.success);
}

t_bool	filecheck(char *file, t_fileinf *inf)
{
	inf->line = NULL;
	if (file == NULL)
		return (error_msg(ERR_BAD_MAT));
	inf->fd = open(file, O_RDONLY);
	if (inf->fd < 3 || !ft_matchend(file, ".mat"))
	{
		free(file);
		return (error_msg(ERR_BAD_MAT));
	}
	free(file);
	return (true);
}

t_bool	parse_material(t_scene *scene, char **line, t_material *mat)
{
	char		*file;
	t_fileinf	inf;
	char		*id;

	material_init(mat);
	if (!parse_color(line, &mat->diffuse))
		return (false);
	id = parse_id(line);
	if (!id)
		return (parse_eol(line));
	if (!ft_match(id, MAT_FLAG))
		return (error_free(ERR_BAD_PREFIX, id));
	free(id);
	file = trim_path(line);
	if (!filecheck(file, &inf))
		return (false);
	if (!read_file(scene, mat, inf))
		return (false);
	return (parse_eol(line));
}

#endif
