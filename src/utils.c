/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 19:44:28 by avallete          #+#    #+#             */
/*   Updated: 2017/03/11 20:52:04 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static size_t		ft_get_elem_max_length(t_dlst *elems, int size)
{
	size_t	maxsize;
	int		i;

	maxsize = 1;
	i = 0;
	while (i < size)
	{
		if (((t_elem*)elems->content)->len > maxsize)
			maxsize = ((t_elem*)elems->content)->len;
		elems = elems->next;
		++i;
	}
	return (maxsize);
}

void				ft_get_columns_infos(t_dlst *args, t_page *page,\
										struct winsize win)
{
	unsigned int column_nb;
	unsigned int column_len;

	column_len = ft_get_elem_max_length(args, page->arguments) + 1;
	if (win.ws_col > 5 && win.ws_row > 5)
	{
		column_nb = win.ws_col / column_len;
		while (column_nb > page->arguments)
		{
			++column_len;
			column_nb = win.ws_col / column_len;
		}
		page->columns_infos.column_len = column_len;
		page->columns_infos.column_nb = column_nb ? column_nb : 1;
		page->elems_per_page = (page->columns_infos.column_nb * win.ws_row);
		if (page->elems_per_page > page->arguments)
			page->elems_per_page = page->arguments;
		page->max_row = (page->arguments / page->columns_infos.column_nb);
		page->page_offset = (page->pos.z / page->elems_per_page);
		page->range_min = (page->elems_per_page * page->page_offset);
		page->range_max = page->range_min + page->range_max;
	}
}

void				ft_smarttrim(char *str, size_t max_len)
{
	char	ret[max_len];
	size_t	len;

	len = ft_strlen(str);
	if (len < max_len)
		ft_bufferize(STDIN_FILENO, str, 0);
	else
	{
		ft_strncpy(ret, str, max_len - 3);
		ret[max_len - 1] = '.';
		ret[max_len - 2] = '.';
		ret[max_len - 3] = '.';
		ret[max_len] = '\0';
	}
	ft_bufferize(STDIN_FILENO, ret, 0);
}

void				ft_clean_screen(t_select *env)
{
	ft_usetermcap("ho", STDIN_FILENO);
	if (tgetstr("DL", NULL) && tgoto(tgetstr("DL", NULL), 0, env->win.ws_row))
		ft_putstr_fd(tgoto(tgetstr("DL", NULL), 0, env->win.ws_row), \
							STDIN_FILENO);
	ft_usetermcap("ho", STDIN_FILENO);
}

void				ft_get_win_size(t_select *env)
{
	ioctl(STDIN_FILENO, TIOCGWINSZ, &(env->win));
}
