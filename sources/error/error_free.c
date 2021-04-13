/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_free.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 15:55:59 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 14:18:28 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <alias.h>
#include <error.h>
#include <stdlib.h>

t_bool	error_free(char *message, void *ptr)
{
	free(ptr);
	return (error_msg(message));
}
