/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 18:04:30 by avallete          #+#    #+#             */
/*   Updated: 2016/06/21 18:08:32 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd(t_dlst **lst, t_dlst *new)
{
	t_dlst *begin;

	begin = *lst;
	new->next = begin;
	*lst = new;
	new->back = NULL;
}
