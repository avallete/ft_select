/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all_page.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 03:51:16 by avallete          #+#    #+#             */
/*   Updated: 2016/08/06 03:55:14 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	ft_print_elems_in_columns(t_select *env)
{
	t_dlst			*tmp;
	unsigned int	i;
	size_t			e;

	i = 0;
	tmp = env->page.start_page_element;
	while (tmp && i < env->page.elems_per_page)
	{
		e = 0;
		while (tmp && e < env->page.columns_infos.column_nb)
		{
			++e;
			print_element(env, (t_elem*)tmp->content);
			tmp = tmp->next;
			++i;
		}
		if (i != env->page.elems_per_page && tmp)
			ft_bufferize(isatty(STDOUT_FILENO), "\n", 0);
	}
}

void		reprint_all_window(t_select *env)
{
	ft_clean_screen(env);
	ft_use_pagination(env, &(env->page));
	ft_print_elems_in_columns(env);
	ft_bufferize(isatty(STDOUT_FILENO), "", 1);
}

void		ft_print_all_page(t_select *env)
{
	if (env->win.ws_col <= 5 || env->win.ws_row <= 5)
		ft_window_too_small(env);
	if (ft_use_pagination(env, &(env->page)))
		reprint_all_window(env);
	ft_bufferize(isatty(STDOUT_FILENO), "", 1);
}
