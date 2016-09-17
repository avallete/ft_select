/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_content_max.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 12:25:40 by avallete          #+#    #+#             */
/*   Updated: 2016/06/21 19:01:51 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_dlst_content_max(t_dlst *lst, size_t (*len_count)(void*))
{
	size_t max;
	size_t len;

	max = 0;
	while (lst)
	{
		len = len_count(lst->content);
		if (len > max)
			max = len;
		lst = lst->next;
	}
	return (max);
}
