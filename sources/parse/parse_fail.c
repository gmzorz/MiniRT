/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_fail.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 15:24:33 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 13:40:45 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <alias.h>
#include <stdlib.h>

t_bool	parse_failure(void *freeable)
{
	free(freeable);
	return (false);
}
