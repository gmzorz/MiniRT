/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_tex_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/21 21:08:22 by goosterl      #+#    #+#                 */
/*   Updated: 2021/02/04 14:37:00 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <utils.h>
#include <error.h>
#include <fcntl.h>
#include <buffer_bonus.h>

static t_texture	*new_texture(void *mlx_ptr, t_texture *add)
{
	t_texture		*new;

	new = (t_texture *)ft_calloc(1, sizeof(t_texture));
	if (new == NULL)
		return (NULL);
	new->map = (t_buffer *)ft_calloc(1, sizeof(t_buffer));
	if (new->map == NULL)
		return (NULL);
	new->file = add->file;
	if (!new_tex_buffer(new->map, mlx_ptr, new->file))
		return (NULL);
	add->map = new->map;
	return (new);
}

static t_bool	texture_exists(t_texture **list, t_texture *add)
{
	t_texture	*start;

	start = *list;
	while (start)
	{
		if (ft_match(start->file, add->file))
		{
			add->map = start->map;
			free(add->file);
			return (true);
		}
		start = start->next;
	}
	return (false);
}

static t_bool	add_texture(void *mlx_ptr, t_texture **list, t_texture *add)
{
	t_texture	*start;

	if (!add)
		return (error_msg(ERR_ADD_TEX));
	if (texture_exists(list, add))
		return (true);
	start = *list;
	if (start)
	{
		while (start->next)
			start = start->next;
		start->next = new_texture(mlx_ptr, add);
		if (!start->next)
			return (error_msg(ERR_ALLOC_TEX));
	}
	else
	{
		*list = new_texture(mlx_ptr, add);
		if (*list == NULL)
			return (error_msg(ERR_ALLOC_TEX));
		start = *list;
	}
	return (true);
}

t_bool	parse_tex(t_scene *scene, char **line, t_texture *tex)
{
	if (tex->map)
		return (error_msg(ERR_TEX_DEF_EXISTS));
	ft_memset(tex, 0, sizeof(t_texture));
	tex->file = trim_path(line);
	if (tex->file == NULL)
		return (error_msg(ERR_BAD_TEX));
	if (!add_texture(scene->mlx.ptr, &scene->textures, tex))
		return (false);
	*line += ft_strspn(*line, DELIM_SPACE);
	return (true);
}
