/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_set_null.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 17:29:28 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:19:13 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <alias.h>
#include <libft.h>

t_bool	error_set_null(void *set, char *message)
{
	ft_putstr_fd(message, 1);
	ft_putchar_fd('\n', 1);
	ft_memset(set, 0, sizeof(set));
	return (false);
}
