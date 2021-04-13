/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_wave_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/27 20:41:53 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:45:58 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <error.h>
#include <libft.h>

t_bool	parse_wave(char **line, t_wave *wave)
{
	char	*uv;

	uv = parse_id(line);
	if (ft_match(uv, "uv") || ft_match(uv, "vu"))
		wave->using = (t_vec2){1.0, 1.0};
	else if (ft_match(uv, "u"))
		wave->using = (t_vec2){1.0, 0.0};
	else if (ft_match(uv, "v"))
		wave->using = (t_vec2){0.0, 1.0};
	else
		return (error_free(ERR_WAVE_UV, uv));
	free(uv);
	if (!parse_unit(line, &wave->amp, false)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_real(line, &wave->freq)
		|| !parse_eol(line))
		return (false);
	return (true);
}
