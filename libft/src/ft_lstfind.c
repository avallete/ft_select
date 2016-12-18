/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 19:44:27 by avallete          #+#    #+#             */
/*   Updated: 2016/09/17 21:46:01 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return the node of the first element
** who match a 0 result to the *f function who compare lst->content to dt.
*/

t_list				*ft_lstfind(t_list *lst, int (*f)(void*, void*), void *data)
{
	while (lst)
	{
		if (!f(lst->content, data))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
