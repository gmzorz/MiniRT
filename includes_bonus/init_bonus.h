/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_bonus.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/02 14:10:16 by goosterl      #+#    #+#                 */
/*   Updated: 2021/03/26 16:47:58 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_BONUS_H
# define INIT_BONUS_H
# include <scene.h>

t_thr_data	*thread_init(t_scene *scene, int idx, t_real *completion,
				pthread_mutex_t *lock);
t_bool		material_init(t_material *mat);

#endif
