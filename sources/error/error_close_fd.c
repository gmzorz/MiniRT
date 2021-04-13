/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_close_fd.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 16:40:27 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:18:34 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <alias.h>
#include <unistd.h>
#include <libft.h>

t_bool	error_close_fd(int fd, char *message)
{
	close(fd);
	ft_putstr_fd(message, 1);
	ft_putchar_fd('\n', 1);
	return (false);
}
