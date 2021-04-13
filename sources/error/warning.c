/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   warning.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 13:14:01 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:23:00 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <alias.h>
#include <libft.h>

t_bool	warning_line(char *line, char *message)
{
	ft_putstr_fd("\033[1;33mWarning:\n\033[4;33m  ", 1);
	ft_putstr_fd(line, 1);
	ft_putstr_fd("\033[0m\n", 1);
	ft_putstr_fd(message, 1);
	ft_putstr_fd("\n\n", 1);
	return (true);
}

t_bool	warning_msg(char *message)
{
	ft_putstr_fd("\033[1;33mWarning:\n\033[0m  ", 1);
	ft_putstr_fd(message, 1);
	ft_putstr_fd("\n", 1);
	return (true);
}
