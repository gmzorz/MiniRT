/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   jump_tables_bonus.h                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 11:22:37 by goosterl      #+#    #+#                 */
/*   Updated: 2021/03/27 21:08:59 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef JUMP_TABLES_BONUS_H
# define JUMP_TABLES_BONUS_H
# if IS_BONUS == 1
#  include <alias.h>
#  include <scene.h>

typedef struct s_jump_btn
{
	int			btn;
	t_bool		(*press)(t_scene *scene);
}	t_jump_btn;

typedef struct s_jump_translate
{
	t_shapetype	type;
	t_bool		(*translate)(t_scene *scene);
}	t_jump_translate;

t_bool	jump_btn(t_scene *scene, int btn, int *idx);
t_bool	jump_translate(t_scene *scene);

# endif
#endif
