/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/27 14:58:27 by avallete          #+#    #+#             */
/*   Updated: 2015/08/27 17:13:24 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_printtab(int *tab, int max)
{
	int i;

	i = 0;
	while (i < max)
	{
		ft_printf("tab [%d][%d]\n", i, tab[i]);
		i++;
	}
}
