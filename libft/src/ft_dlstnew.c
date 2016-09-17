/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 02:48:17 by avallete          #+#    #+#             */
/*   Updated: 2016/06/21 18:03:36 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlst	*ft_dlstnew(void *content, size_t content_size)
{
	t_dlst *new;

	if ((new = (t_dlst*)malloc(sizeof(t_dlst))))
	{
		new->content = content;
		new->content_size = content_size;
		new->next = NULL;
		new->back = NULL;
	}
	return (new);
}
