/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_get_node_index.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 19:20:10 by avallete          #+#    #+#             */
/*   Updated: 2016/06/23 19:27:04 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_dlst_get_node_index(t_dlst *list_begin, t_dlst *node)
{
	int i;

	i = 0;
	while (list_begin)
	{
		if (list_begin == node)
			return (i);
		++i;
		list_begin = list_begin->next;
	}
	return (-1);
}
