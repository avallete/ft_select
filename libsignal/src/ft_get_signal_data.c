/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_signal_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 18:17:12 by avallete          #+#    #+#             */
/*   Updated: 2016/06/07 18:17:49 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_signal.h>

/*
** Fuction used to pass the context datas through signal handler
** without use a global variable.
*/

t_signal			*ft_get_signal_data(t_signal *env)
{
	static t_signal *data;

	if (env && env != data)
		data = env;
	return (data);
}
