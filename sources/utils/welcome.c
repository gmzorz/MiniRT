/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   welcome.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/10 10:27:09 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/13 11:44:34 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	print_welcome(void)
{
	ft_putstr_fd("miniRT: My first RayTracer with miniLibX\n", 1);
	ft_putstr_fd("usage:	./minirt file.rt\n", 1);
	ft_putstr_fd("flags:	--save\n", 1);
	exit(EXIT_SUCCESS);
}
