/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_get_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 18:24:11 by avallete          #+#    #+#             */
/*   Updated: 2016/12/15 12:41:36 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_dlst	*ft_dlst_get_elem_index(t_dlst *lst, unsigned int index)
{
	while (lst && index-- > 0)
		lst = lst->next;
	return (lst);
}
