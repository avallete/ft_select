/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usetermcap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 03:30:25 by avallete          #+#    #+#             */
/*   Updated: 2016/08/21 16:41:13 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int		ft_put(int c)
{
	write(isatty(STDOUT_FILENO), &c, 1);
	return (0);
}

void			ft_usetermcap(char *capacity, int fd)
{
	char *res;

	res = tgetstr(capacity, NULL);
	if (res)
		tputs(res, fd, ft_put);
}
