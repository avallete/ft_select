/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 03:11:23 by avallete          #+#    #+#             */
/*   Updated: 2016/08/21 17:16:24 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	ft_fill_str(char *str, char fill, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		str[i] = fill;
		++i;
	}
	str[i] = '\0';
}

static void	ft_print_elem(t_elem *elem, size_t max_len)
{
	if (elem->mode & IS_HOVERED)
		ft_bufferize(STDIN_FILENO, tgetstr("us", NULL), 0);
	if (elem->mode & IS_SELECTED)
		ft_bufferize(STDIN_FILENO, tgetstr("mr", NULL), 0);
	if (elem->color)
		ft_bufferize(STDIN_FILENO, elem->color, 0);
	if ((elem->mode & (IS_HOVERED | IS_SELECTED)) != (IS_HOVERED | IS_SELECTED)\
			&& elem->len > max_len)
		ft_smarttrim(elem->name, max_len);
	else
		ft_bufferize(STDIN_FILENO, elem->name, 0);
	if (elem->color)
		ft_bufferize(STDIN_FILENO, "\033[m", 0);
	if (elem->mode & IS_HOVERED)
		ft_bufferize(STDIN_FILENO, tgetstr("ue", NULL), 0);
	if (elem->mode & IS_SELECTED)
		ft_bufferize(STDIN_FILENO, tgetstr("me", NULL), 0);
}

static void	ft_print_padded(t_elem *elem, int lpad, int rpad, size_t max_len)
{
	char leftpad[lpad];
	char rightpad[rpad];

	ft_fill_str(leftpad, ' ', lpad);
	ft_fill_str(rightpad, ' ', rpad);
	ft_bufferize(STDIN_FILENO, leftpad, 0);
	ft_print_elem(elem, max_len);
	ft_bufferize(STDIN_FILENO, rightpad, 0);
}

void		print_element(t_select *env, t_elem *elem)
{
	int right_pad;

	if (env->page.columns_infos.column_nb > 1)
	{
		right_pad = env->page.columns_infos.column_len - elem->len;
		ft_print_padded(elem, 0, right_pad, env->win.ws_col);
	}
	else
		ft_print_elem(elem, env->win.ws_col);
}

void		ft_print_current_elem(t_select *env)
{
	char *cm;
	char *res;

	cm = tgetstr("cm", NULL);
	res = tgoto(cm, (env->page.relpos.x * env->page.columns_infos.column_len),\
			env->page.relpos.y);
	ft_bufferize(STDIN_FILENO, res, 0);
	print_element(env, env->page.current_element->content);
	ft_bufferize(STDIN_FILENO, "", 1);
}
