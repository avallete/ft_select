/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 20:12:17 by avallete          #+#    #+#             */
/*   Updated: 2016/08/22 19:29:46 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void				ft_close_terminal(void *data)
{
	ft_clean_screen((t_select*)data);
	ft_usetermcap("te", STDIN_FILENO);
	ft_usetermcap("ve", STDIN_FILENO);
	if (((t_select*)data)->restore_term)
	{
		while (tcsetattr(STDIN_FILENO, TCSANOW, \
						&(((t_select*)data)->termold)) == -1)
		{
		}
	}
	((t_select*)data)->print = 0;
}

/*
** Must send ctrl+z char to bypass read blocking. (ioctl)
*/

void					sigtstp_handle(void *data)
{
	if (((t_select*)data)->restore_term)
		ft_close_terminal(data);
	signal(SIGTSTP, SIG_DFL);
	ioctl(STDIN_FILENO, TIOCSTI, KEY_CTRL_Z);
}

void					ft_quit(void *term)
{
	if (((t_select*)term)->restore_term)
		ft_close_terminal(term);
	delete_all(((t_select*)term)->args);
	exit(0);
}

void					ft_terminate(void *term)
{
	if (((t_select*)term)->restore_term)
		ft_close_terminal(term);
	print_selected_elements(((t_select*)term)->args);
	delete_all(((t_select*)term)->args);
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
