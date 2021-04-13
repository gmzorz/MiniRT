/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_skybox_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/31 20:06:56 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:38:36 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <parse.h>
# include <error.h>

t_bool	parse_skybox(t_scene *scene, char **line)
{
	t_real	emission;

	if (scene->skybox.t_diffuse.map)
		return (error_msg(ERR_SKY_EXISTS));
	if (!parse_tex(scene, line, &scene->skybox.t_diffuse))
		return (false);
	if (!parse_real(line, &emission))
		return (error_msg(ERR_MISSING_EMIS));
	if (!parse_skip(line, DELIM_SPACE, 0)
		|| !parse_bool(line, &scene->skybox.t_diffuse.map->de_gamma))
		return (error_msg(ERR_MISSING_GMMA));
	if (!parse_eol(line))
		return (false);
	scene->skybox.emission = (t_rgb){emission, emission, emission};
	return (true);
}

#endif
