/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   brdf_threading_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/02 14:01:52 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/13 00:14:38 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <minirt.h>
#include <math.h>
#include <stdlib.h>
#include <error.h>
#include <init.h>
#include <events.h>

static void	thread_completion(t_thr_data *data, t_real add)
{
	pthread_mutex_lock(data->lock);
	if (*data->completion == 0.0)
		console_putnn("|");
	if (floor(*data->completion) < floor(*data->completion + add))
		write(1, "=", 1);
	*data->completion += add;
	if (floor(*data->completion) == 50)
		write(1, "|\n", 2);
	pthread_mutex_unlock(data->lock);
}

static void	thread_range(t_real *range, t_thr_data *data)
{
	range[0] = data->scene->main.height / data->scene->brdf_threadnum;
	if (data->idx + 1 == data->scene->brdf_threadnum)
		range[1] = data->scene->main.height;
	else
		range[1] = range[0] * (data->idx + 1);
	range[0] = range[0] * data->idx;
}

static void	*thread_render(void *catch)
{
	t_thr_data	*data;
	t_real		range[2];
	t_rgb		color;
	t_real		progadd;
	int			idx;

	data = catch;
	thread_range(range, data);
	color = vec3_zero();
	progadd = 50.0 / data->scene->main.width / data->scene->brdf_threadnum;
	idx = 0;
	while (idx < data->scene->main.width)
	{
		while (range[0] < range[1])
		{
			compute_pixel(data->scene, (t_vec2){idx, range[0]});
			range[0] += 1;
		}
		thread_completion(data, progadd);
		range[0] = 0;
		idx += 1;
	}
	free(data);
	return (NULL);
}

static void	threads_run(pthread_t *threads, t_thr_data *data,
	pthread_mutex_t *mutex)
{
	int	idx;

	idx = 0;
	while (idx < data->scene->brdf_threadnum)
	{
		pthread_join(threads[idx], NULL);
		idx += 1;
	}
	pthread_mutex_destroy(mutex);
	free(threads);
}

t_bool	brdf_threading(t_scene *scene)
{
	t_thr_data		*data;
	pthread_t		*threads;
	pthread_mutex_t	mutex;
	t_real			completion;
	int				idx;

	pthread_mutex_init(&mutex, NULL);
	threads = malloc(sizeof(pthread_t) * scene->brdf_threadnum);
	if (threads == NULL)
		return (error_msg(ERR_ALLOC_THREADS));
	idx = 0;
	console_put(RT_RENDER);
	while (idx < scene->brdf_threadnum)
	{
		data = thread_init(scene, idx, &completion, &mutex);
		if (data == NULL)
			return (error_msg(ERR_ALLOC_THR_DATA));
		pthread_create(&threads[idx], NULL, thread_render, data);
		idx += 1;
	}
	threads_run(threads, data, &mutex);
	if (scene->brdf_save)
		take_screenshot(scene);
	return (true);
}
