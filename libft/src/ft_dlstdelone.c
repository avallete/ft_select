/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 18:11:21 by avallete          #+#    #+#             */
/*   Updated: 2016/08/17 15:40:43 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function delete the element lst from a list.
** Linking the adjacent nodes together.
** And call the destructor function giving him the *content of the node.
*/

void	ft_dlstdelone(t_dlst **lst, void (*destructor)(void *))
{
	if (*lst)
	{
		if ((*lst)->back)
			(*lst)->back->next = (*lst)->next;
		if ((*lst)->next)
			(*lst)->next->back = (*lst)->back;
		(*destructor)((*lst)->content);
		free((*lst));
		*lst = NULL;
	}
}
