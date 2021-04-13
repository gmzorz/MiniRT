/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 14:16:40 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:13:25 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <alias.h>
#include <unistd.h>

void	write_bin(t_bool *check, int fd, void *value, int size)
{
	if (*check == false)
		return ;
	if (write(fd, &value, size))
		return ;
	else
		*check = false;
}

void	write_def(t_bool *check, int fd, void *value, int size)
{
	if (*check == false)
		return ;
	if (write(fd, value, size))
		return ;
	else
		*check = false;
}
