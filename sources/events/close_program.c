/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   close_program.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/10 16:18:24 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:39:37 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>

int	close_program(t_scene *scene)
{
	free_and_exit(scene);
	return (1);
}
