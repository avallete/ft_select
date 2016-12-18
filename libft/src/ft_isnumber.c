/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 17:43:57 by avallete          #+#    #+#             */
/*   Updated: 2016/09/22 17:57:57 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_isnumber(const char *str)
{
	int i;

	i = 0;
	if (str && *str)
	{
		if (str[i] == '-' || str[i] == '+')
			++i;
		while (str[i])
		{
			if (!(ft_isdigit(str[i])))
				return (0);
			++i;
		}
		return (1);
	}
	return (0);
}
