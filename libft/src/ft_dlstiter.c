/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/30 00:40:08 by avallete          #+#    #+#             */
/*   Updated: 2016/06/21 19:01:22 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstiter(t_dlst *list, void (*f)(t_dlst *elem))
{
	if (list)
	{
		while (list->back)
			list = list->back;
		while (list)
		{
			f(list);
			list = list->next;
		}
	}
}
