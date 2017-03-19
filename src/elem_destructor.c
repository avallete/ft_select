/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_destructor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 23:18:53 by avallete          #+#    #+#             */
/*   Updated: 2016/08/21 19:11:14 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void				elem_destructor(void *elem)
{
	t_elem *tmp;

	tmp = (t_elem*)elem;
	if (tmp->origname)
		free(tmp->origname);
	if (tmp->name)
		free(tmp->name);
	tmp->name = NULL;
	free(elem);
}
