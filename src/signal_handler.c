/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 20:12:17 by avallete          #+#    #+#             */
/*   Updated: 2016/08/19 16:53:25 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void				ft_close_terminal(void *data)
{
	ft_clean_screen((t_select*)data);
	ft_usetermcap("te", isatty(STDOUT_FILENO));
	ft_usetermcap("ve", isatty(STDOUT_FILENO));
	while (tcsetattr(STDOUT_FILENO, TCSANOW,\
				&(((t_select*)data)->termold)) == -1)
	{
	}
	((t_select*)data)->print = 0;
}

void					sigtstp_handle(void *data)
{
	if (((t_select*)data)->restore_term)
		ft_close_terminal(data);
	signal(SIGTSTP, SIG_DFL);
	ioctl(isatty(STDOUT_FILENO), TIOCSTI, KEY_CTRL_Z);
}

void					ft_quit(void *term)
{
	delete_all(((t_select*)term)->args);
	if (((t_select*)term)->restore_term)
		ft_close_terminal(term);
	exit(0);
}

void					ft_update_term_infos(void *env)
{
	t_select *data;

	data = (t_select*)env;
	ft_get_win_size(data);
	if (data->win.ws_col > 5 && data->win.ws_row > 5)
	{
		ft_get_columns_infos(data->args, &(data->page), data->win);
		data->page.range_min = data->page.elems_per_page *\
								data->page.page_offset;
		data->page.range_max = data->page.range_min + data->page.elems_per_page;
		data->page.pos = get_element_position_from_index(
							data->page.pos.z, &(data->page));
		data->page.relpos = get_current_element_relative_position(\
													&(data->page), data->win);
		data->page.start_page_element = ft_dlst_get_elem_index(\
											data->args, data->page.range_min);
		reprint_all_window(data);
	}
	else
	{
		data->wait = 1;
		ft_window_too_small(data);
	}
}
