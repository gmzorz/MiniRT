/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_aa_bonus.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/27 10:12:05 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:38:08 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <parse.h>
# include <error.h>

t_bool	parse_aa(t_scene *scene, char **line)
{
	if (scene->aa_enable == true)
		return (error_msg(ERR_AA_EXISTS));
	scene->aa_enable = true;
	if (!parse_int(line, &scene->aa_samples)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_bool(line, &scene->aa_accel)
		|| !parse_eol(line))
		return (false);
	if (scene->aa_samples > 64)
		warning_msg(WARN_AA_SAMPLES);
	return (true);
}

#endif
