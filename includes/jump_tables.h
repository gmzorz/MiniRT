/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   jump_tables.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 11:22:37 by goosterl      #+#    #+#                 */
/*   Updated: 2021/03/25 14:35:44 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef JUMP_TABLES_H
# define JUMP_TABLES_H
# include <alias.h>
# include <scene.h>
# if IS_BONUS == 1
#  include <jump_tables_bonus.h>
# endif

typedef struct s_jump_parse
{
	char		*id;
	t_bool		(*parse)(t_scene *scene, char **line);
}	t_jump_parse;

typedef struct s_jump_key
{
	int			key;
	t_bool		(*press)(t_scene *scene);
}	t_jump_key;

typedef struct s_jump_intersect
{
	t_shapetype	type;
	t_bool		(*intersect)(t_shapes *shapes, t_hitrecord *rec);
}	t_jump_intersect;

typedef struct s_jump_construct
{
	t_shapetype	type;
	t_bool		(*construct)(t_shapes *shapes);
}	t_jump_construct;

typedef struct s_jump_shader
{
	t_mode		mode;
	t_rgb		(*shader)(t_scene *scene, t_hitrecord *rec);
}	t_jump_shader;

t_bool	jump_shader(t_scene *scene, t_hitrecord *rec, t_rgb *col);
t_bool	jump_parse(t_scene *scene, char **line);
t_bool	jump_intersect(t_shapes *shape, t_hitrecord *rec);
t_bool	jump_construct(t_shapes *shape);
t_bool	jump_key(t_scene *scene, int key);

#endif
