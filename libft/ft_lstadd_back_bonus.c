/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 19:29:14 by goosterl      #+#    #+#                 */
/*   Updated: 2019/11/28 22:01:41 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *newlist)
{
	if (*alst == NULL)
	{
		*alst = newlist;
		newlist->next = NULL;
	}
	else
		ft_lstlast(*alst)->next = newlist;
}
