/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 14:30:29 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:23:33 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#include <fcntl.h>
#include <libft.h>
#include <error.h>
#include <jump_tables.h>

t_bool	parse_to_scene(t_scene *scene, const char *rt_file)
{
	t_fileinf	info;
	int			idx;

	info.success = true;
	info.fd = open(rt_file, O_RDONLY);
	if (!ft_matchend(rt_file, ".rt"))
		return (error_msg(ERR_PAR_EXT));
	if (info.fd < 3)
		return (error_msg(ERR_WRONG_FD));
	idx = 0;
	while (get_next_line(info.fd, &info.line) > 0)
	{
		info.line_cpy = info.line;
		idx += 1;
		if (!jump_parse(scene, &info.line))
			info.success = error_line(info.line_cpy);
		free(info.line_cpy);
	}
	free(info.line);
	close(info.fd);
	return (info.success);
}
