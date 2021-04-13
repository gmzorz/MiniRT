/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   random_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/16 15:48:59 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/12 16:56:32 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <alias.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void	rand_init(void)
{
	srand(time(NULL) * getpid());
}

t_real	rt_rand(void)
{
	return (rand() / (float)RAND_MAX);
}

t_real	rt_urand(void)
{
	return ((rand() / (float)RAND_MAX - 0.5) * 2);
}
