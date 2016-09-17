/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_too_small.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 03:55:46 by avallete          #+#    #+#             */
/*   Updated: 2016/08/06 03:56:29 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_window_too_small(t_select *env)
{
	ft_clean_screen(env);
	ft_putendl("error window too small");
	while (env->win.ws_col <= 5 || env->win.ws_row <= 5)
		ft_get_win_size(env);
	env->wait = 0;
}
