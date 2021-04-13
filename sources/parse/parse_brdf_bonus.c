/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_brdf_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/18 12:12:45 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/13 00:14:11 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <parse.h>
# include <error.h>
# include <libft.h>

t_bool	parse_brdf(t_scene *scene, char **line)
{
	char	*save;

	if (scene->brdf_spp || scene->brdf_depth)
		return (error_msg(ERR_BRDF_EXISTS));
	if (!parse_int(line, &scene->brdf_spp)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_int(line, &scene->brdf_depth))
		return (false);
	save = parse_id(line);
	if (ft_match(save, RT_SAVE_SS))
	{
		scene->brdf_save = true;
		free(save);
	}
	else if (save)
		return (error_free(ERR_UNUSED_PARAM, save));
	else if (!parse_eol(line))
		return (false);
	if (scene->brdf_spp < 1)
		return (error_msg(ERR_SPP_NEG));
	if (scene->brdf_depth < 1)
		return (error_msg(ERR_DPT_NEG));
	scene->brdf = true;
	return (true);
}

#endif
