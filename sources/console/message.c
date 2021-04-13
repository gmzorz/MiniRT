/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   message.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/11 13:44:42 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:40:13 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 0
# include <libft.h>

void	console_putstr(char *message, char *str)
{
	ft_putstr_fd("[\033[1;32mminiRT\033[0m]: ", 1);
	ft_putstr_fd(message, 1);
	ft_putstr_fd(" \033[4m", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\033[0m\n", 1);
}

void	console_put(char *message)
{
	ft_putstr_fd("[\033[1;32mminiRT\033[0m]: ", 1);
	ft_putstr_fd(message, 1);
	ft_putchar_fd('\n', 1);
}

void	console_putnn(char *message)
{
	ft_putstr_fd("[\033[1;32mminiRT\033[0m]: ", 1);
	ft_putstr_fd(message, 1);
}

#endif
