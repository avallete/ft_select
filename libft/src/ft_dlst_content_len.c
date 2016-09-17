/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dslt_content_len.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 12:24:06 by avallete          #+#    #+#             */
/*   Updated: 2016/06/21 19:04:27 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_dlst_content_len(t_dlst *lst, size_t (*len_count)(void*))
{
	return (len_count(lst->content));
}
