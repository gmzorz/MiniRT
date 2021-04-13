/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_brdf_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/01 15:50:26 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:44:31 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <error.h>
# include <minirt.h>

t_bool	render_brdf(t_scene *scene)
{
	if (scene->brdf == false)
	{
		warning_msg(WARN_BRDF_SET);
		scene->brdf_spp = 16;
		scene->brdf_depth = 4;
	}
	console_put(DEBUG_BRDF);
	scene->viewport = brdf;
	return (true);
}

#endif
