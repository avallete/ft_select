/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 18:54:44 by avallete          #+#    #+#             */
/*   Updated: 2016/08/03 12:57:29 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_signal.h>

/*
** Signal handler top level.
*/

void				ft_sighandler(int signal)
{
	ft_parse_signal(ft_get_signal_data((t_signal*)0), signal);
}

/*
** Init the array of pointer handlers from 0 to size with NULL pointer.
*/

void				ft_sig_handler_init(t_func_handler handlers[UNIX_SIG_LEN])
{
	size_t i;

	i = 0;
	while (i < UNIX_SIG_LEN)
	{
		handlers[i] = (void*)0;
		i++;
	}
}

/*
** Init and put a signal watcher for each signal who have a watcher
** initialized in env->sig_handler.
*/

void				ft_signal_watch(t_signal *env)
{
	size_t i;

	i = 1;
	ft_get_signal_data(env);
	while (i <= UNIX_SIG_LEN)
	{
		if (env->sig_handler[i])
			signal(i, &ft_sighandler);
		i++;
	}
}
