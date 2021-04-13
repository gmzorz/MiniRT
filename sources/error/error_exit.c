/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_exit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 16:39:21 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/13 11:44:13 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	error_exit(char *message)
{
	ft_putstr_fd("\033[1;31mError\033[0m\n", 1);
	ft_putstr_fd(message, 1);
	ft_putchar_fd('\n', 1);
	exit (EXIT_FAILURE);
}
