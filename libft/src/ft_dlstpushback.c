/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstpushback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 19:26:02 by avallete          #+#    #+#             */
/*   Updated: 2016/06/21 18:07:03 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstpushback(t_dlst **lst, t_dlst *new)
{
	t_dlst *begin;

	begin = *lst;
	if (begin)
	{
		while (begin->next)
			begin = begin->next;
		begin->next = new;
		new->back = begin;
	}
}
