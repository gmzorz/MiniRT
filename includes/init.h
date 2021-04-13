/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 16:35:29 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 17:27:47 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H
# include <scene.h>
# include <shapes.h>
# if IS_BONUS == 1
#  include <init_bonus.h>
# endif

t_bool		scene_init(t_scene *scene, char *rt_file);
t_scene		*scene_allocate(void);
t_bool		scene_verify(t_scene *scene);
t_bool		buffer_init(t_scene *scene);
t_bool		hook_init(t_scene *scene);
t_bool		camera_ray_init(t_scene *scene, t_ray *ray, t_real u, t_real v);
t_bool		volume_init(t_aabb *volume);

#endif