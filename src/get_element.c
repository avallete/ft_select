/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 03:02:30 by avallete          #+#    #+#             */
/*   Updated: 2016/08/06 03:10:32 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_vect				get_element_position_from_index(unsigned int index,\
													t_page *page)
{
	t_vect pos;

	pos.y = (index / page->columns_infos.column_nb);
	pos.x = (index % page->columns_infos.column_nb);
	pos.z = index;
	return (pos);
}

t_vect				get_current_element_relative_position(t_page *page,\
															struct winsize win)
{
	t_vect pos;

	pos.x = 0;
	pos.y = 0;
	pos.x = page->pos.x;
	if (page->page_offset)
		pos.y = (page->pos.y) - (win.ws_row * page->page_offset);
	else
		pos.y = page->pos.y;
	return (pos);
}

void				get_next_element(t_select *env)
{
	if (env->page.pos.z + 1 < env->page.arguments)
		env->page.pos = get_element_position_from_index(env->page.pos.z + 1,\
				&(env->page));
	else
		env->page.pos = get_element_position_from_index(0, &(env->page));
}
