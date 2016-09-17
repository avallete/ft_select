/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 02:36:21 by avallete          #+#    #+#             */
/*   Updated: 2016/08/21 19:09:21 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		key_up_down(t_select *env)
{
	unsigned int nb_cols;
	unsigned int arguments;

	nb_cols = env->page.columns_infos.column_nb;
	arguments = env->page.arguments;
	if (!ft_strcmp(KEY_UP, env->buf) && !env->wait)
	{
		if (env->page.pos.y == 0)
		{
			if ((int)((arguments % nb_cols) - env->page.pos.x) > 0)
				env->page.pos.y = env->page.max_row;
			else
				env->page.pos.y = env->page.max_row - 1;
		}
		else
			env->page.pos.y -= 1;
	}
	if (!ft_strcmp(KEY_DOWN, env->buf) && !env->wait)
	{
		if ((env->page.pos.y + 1) > env->page.max_row ||
			((env->page.pos.y + 1) * nb_cols) + env->page.pos.x >= arguments)
			env->page.pos.y = 0;
		else
			env->page.pos.y = env->page.pos.y + 1;
	}
}

static void		key_left_right(t_select *env)
{
	unsigned int nb_cols;
	unsigned int arguments;

	nb_cols = env->page.columns_infos.column_nb;
	arguments = env->page.arguments;
	if (!ft_strcmp(KEY_LEFT, env->buf) && !env->wait)
	{
		if (nb_cols > 1)
		{
			env->page.pos.x = env->page.pos.x > 0 ?\
								(env->page.pos.x - 1 % nb_cols) : nb_cols - 1;
			while ((env->page.pos.y * nb_cols) + env->page.pos.x >= arguments)
				env->page.pos.x--;
		}
	}
	if (!ft_strcmp(KEY_RIGHT, env->buf) && !env->wait)
	{
		if (env->page.pos.x <= nb_cols && nb_cols > 1)
			env->page.pos.x = (env->page.pos.x + 1) % nb_cols;
		if ((env->page.pos.y * nb_cols) + env->page.pos.x >= arguments)
			env->page.pos.x = 0;
	}
}

static void		parse_keys_delete(t_select *env)
{
	if (!ft_strcmp(KEY_MAJ_D, env->buf))
	{
		if (is_selected_elements(env))
		{
			delete_selected_elements(env);
			((t_elem*)env->page.current_element->content)->mode ^= IS_HOVERED;
			env->page.current_element = env->args;
			env->page.start_page_element = env->args;
			init_cursor_position(env);
			((t_elem*)env->page.current_element->content)->mode ^= IS_HOVERED;
			ft_update_term_infos(env);
		}
	}
	if (!ft_strcmp(KEY_BACKSPACE, env->buf) || !ft_strcmp(KEY_DELETE, env->buf))
	{
		delete_current_element(env);
		((t_elem*)env->page.current_element->content)->mode ^= IS_HOVERED;
		ft_update_term_infos(env);
	}
}

void			get_input(t_select *env)
{
	ft_bzero(env->buf, 5);
	read(0, env->buf, 4);
	key_up_down(env);
	key_left_right(env);
	parse_keys_delete(env);
	if (!ft_strcmp(KEY_ESCAPE, env->buf))
		ft_quit(env);
	if (!ft_strcmp(KEY_SPACE, env->buf))
	{
		((t_elem*)env->page.current_element->content)->mode ^= IS_SELECTED;
		get_next_element(env);
	}
	if (!ft_strcmp(KEY_ENTER, env->buf))
		ft_terminate(env);
}
