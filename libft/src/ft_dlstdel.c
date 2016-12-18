/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 21:30:08 by avallete          #+#    #+#             */
/*   Updated: 2016/09/17 21:44:54 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_dlstdel(t_dlst **lst, void (*destructor)(void *))
{
	if (lst && *lst)
	{
		while ((*lst)->back)
			lst = &((*lst)->back);
		while ((*lst)->next)
			ft_dlstdelone(&((*lst)->next), destructor);
		ft_dlstdelone(lst, destructor);
	}
}
