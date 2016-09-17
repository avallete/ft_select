/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pagination.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 02:59:27 by avallete          #+#    #+#             */
/*   Updated: 2016/08/06 03:02:12 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void			page_prev(t_select *env, t_page *page)
{
	page->range_min -= page->elems_per_page;
	page->range_max -= page->elems_per_page;
	page->start_page_element = ft_dlst_get_elem_index(\
													env->args, page->range_min);
	page->page_offset -= 1;
}

static void			page_next(t_select *env, t_page *page)
{
	page->range_min += page->elems_per_page;
	page->range_max += page->elems_per_page;
	page->start_page_element = ft_dlst_get_elem_index(\
													env->args, page->range_min);
	page->page_offset += 1;
}

int					ft_use_pagination(t_select *env, t_page *page)
{
	if (page->pos.z < page->range_max && page->pos.z > page->range_min)
		return (0);
	while (page->pos.z >= page->range_max)
		page_next(env, page);
	while (page->pos.z < page->range_min)
		page_prev(env, page);
	page->relpos = get_current_element_relative_position(page, env->win);
	return (1);
}
