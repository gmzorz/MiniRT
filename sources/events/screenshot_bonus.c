/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   screenshot_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 15:52:29 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/13 13:35:17 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <bitmap.h>
#include <dirent.h>
#include <sys/stat.h>
#include <minirt.h>
#include <error.h>
#include <events.h>

static t_bool	verify_dir(void)
{
	int			dir_success;
	DIR			*dir;

	dir = opendir(SS_DIR);
	if (dir == NULL)
	{
		dir_success = mkdir(SS_DIR, 0777);
		console_put(SS_DIR_CREATE);
		sleep(1);
		if (dir_success == -1)
			return (false);
		return (true);
	}
	closedir(dir);
	return (true);
}

t_bool	finish_up(t_scene *scene, char *filename)
{
	if (!save_bmp(&scene->main, filename))
	{
		free(filename);
		return (false);
	}
	console_putstr(RT_SS, filename);
	free(filename);
	scene->do_update = false;
	return (true);
}

t_bool	take_screenshot(t_scene *scene)
{
	time_t		current_time;
	char		*filename[2];
	char		*dt;

	current_time = time(NULL);
	dt = ctime(&current_time);
	if (dt == NULL)
	{
		warning_msg(WARN_FETCH_DT);
		filename[1] = ft_strdup(SS_DEF);
	}
	else
	{
		dt[ft_strlen(dt) - 1] = '\0';
		filename[1] = ft_strjoin(dt, ".bmp");
	}
	if (verify_dir() == true)
		filename[0] = ft_strjoin(SS_DIR, filename[1]);
	else
		filename[0] = ft_strdup(filename[1]);
	free(filename[1]);
	return (finish_up(scene, filename[0]));
}
