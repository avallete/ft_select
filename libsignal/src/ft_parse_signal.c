/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_signal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 18:16:19 by avallete          #+#    #+#             */
/*   Updated: 2016/06/07 20:04:26 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_signal.h>

/*
** Get the signal and the env context data.
** She call the function stored the array of functions pointer env->sig_handler.
*/

void				ft_parse_signal(t_signal *env, int signal)
{
	if (env->sig_handler[signal])
		((env->sig_handler)[signal])(env->data);
}
