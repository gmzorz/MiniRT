/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_threads_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/02 14:58:15 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:46:10 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <error.h>

t_bool	parse_threads(t_scene *scene, char **line)
{
	if (scene->brdf_threading == true)
		return (error_msg(ERR_THR_EXISTS));
	scene->brdf_threading = true;
	if (!parse_int(line, &scene->brdf_threadnum)
		|| !parse_eol(line))
		return (false);
	if (scene->brdf_threadnum <= 0)
		return (error_msg(ERR_INVALID_THRDNUM));
	return (true);
}
