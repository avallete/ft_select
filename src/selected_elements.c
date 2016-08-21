/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selected_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 03:46:31 by avallete          #+#    #+#             */
/*   Updated: 2016/08/21 20:02:35 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	change_selected_element(t_select *env)
{
	t_elem			*old;
	t_page			page;
	unsigned int	elem_index;
	unsigned int	old_index;

	page = env->page;
	old = ((t_elem*)env->page.current_element->content);
	old_index = ft_dlst_get_node_index(env->args, env->page.current_element);
	((t_elem*)env->page.current_element->content)->mode ^= IS_HOVERED;
	if (old_index >= env->page.range_min && old_index < env->page.range_max)
		ft_print_current_elem(env);
	elem_index = (page.pos.y * page.columns_infos.column_nb) + page.pos.x;
	env->page.current_element = ft_dlst_get_elem_index(env->args, elem_index);
	env->page.relpos = get_current_element_relative_position(&(env->page),\
			env->win);
	((t_elem*)env->page.current_element->content)->mode ^= IS_HOVERED;
	ft_print_current_elem(env);
	env->page.pos.z = elem_index;
	if (old->len > env->win.ws_col ||\
		((t_elem*)env->page.current_element->content)->len > env->win.ws_col)
		reprint_all_window(env);
}

int		is_selected_elements(t_select *env)
{
	t_dlst *tmp;

	tmp = env->args;
	while (tmp)
	{
		if (((t_elem*)tmp->content)->mode & IS_SELECTED)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	print_selected_elements(t_dlst *args)
{
	int i;

	i = 0;
	while (args)
	{
		if (((t_elem*)args->content)->mode & IS_SELECTED)
		{
			if (i)
				ft_putstr(" ");
			ft_putstr(((t_elem*)args->content)->name);
			++i;
		}
		args = args->next;
	}
}
