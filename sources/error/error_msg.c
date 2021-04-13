/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_msg.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 13:49:37 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/13 11:46:41 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <alias.h>
#include <libft.h>

t_bool	error_line(char *line)
{
	ft_putstr_fd("  Line: \033[1;34m", 1);
	ft_putstr_fd(line, 1);
	ft_putstr_fd("\n\033[0m", 1);
	return (false);
}

t_bool	error_msg(char *message)
{
	ft_putstr_fd("\033[1;31mError\033[0m\n  ", 1);
	ft_putstr_fd(message, 1);
	ft_putchar_fd('\n', 1);
	return (false);
}
