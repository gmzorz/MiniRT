/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   material_init_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/26 16:47:16 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 17:57:25 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <color.h>
#include <libft.h>

/*
**	defaults
*/

t_bool	material_init(t_material *mat)
{
	ft_memset(mat, 0, sizeof(t_material));
	mat->specular = (t_vec3){1.0, 1.0, 1.0};
	mat->gloss = 0.75;
	mat->reflection = (t_vec3){0.2, 0.2, 0.2};
	mat->emission = (t_vec3){0.0, 0.0, 0.0};
	mat->roughness = 0.5;
	mat->tex_size_y = 1.0;
	mat->tex_size_x = 1.0;
	return (true);
}
