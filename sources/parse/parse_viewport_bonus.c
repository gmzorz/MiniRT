/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_viewport_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/23 15:05:59 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:46:19 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <error.h>
#include <libft.h>

t_bool	parse_viewport(t_scene *scene, char **line)
{
	char	*input;

	input = parse_id(line);
	if (ft_match(input, VP_FULL))
		scene->viewport_scale = 1;
	else if (ft_match(input, VP_HALF))
		scene->viewport_scale = 2;
	else if (ft_match(input, VP_QUARTER))
		scene->viewport_scale = 4;
	else
		return (error_free(ERR_VP_SCALE, input));
	free(input);
	return (parse_eol(line));
}
