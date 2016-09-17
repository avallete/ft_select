/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_circlelist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 19:03:32 by avallete          #+#    #+#             */
/*   Updated: 2016/06/21 19:05:53 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Perfom the linking between the first and last element of list.
*/

void	ft_circlelist(t_dlst **list)
{
	t_dlst *begin;
	t_dlst *end;

	begin = *list;
	end = *list;
	if (begin)
	{
		while (end->next)
			end = end->next;
		end->next = begin;
	}
}
