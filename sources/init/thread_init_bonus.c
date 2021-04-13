/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   thread_init_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/02 14:02:35 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:32:43 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>
#include <libft.h>

t_thr_data	*thread_init(t_scene *scene, int idx, t_real *completion,
	pthread_mutex_t *lock)
{
	t_thr_data	*data;

	data = (t_thr_data *)ft_calloc(1, sizeof(t_thr_data));
	if (data == NULL)
		return (NULL);
	*completion = 0;
	data->scene = scene;
	data->idx = idx;
	data->completion = completion;
	data->lock = lock;
	return (data);
}
