/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_free_and_exit.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 13:26:23 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/13 11:46:21 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <events.h>
#include <minirt.h>

t_bool	error_free_and_exit(t_scene *scene, char *message)
{
	console_put(message);
	free_and_exit(scene);
	return (false);
}
