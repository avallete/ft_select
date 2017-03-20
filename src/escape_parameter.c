/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape_parameter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 18:17:59 by avallete          #+#    #+#             */
/*   Updated: 2017/03/20 18:20:59 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

char				*escape_parameter(const char *src)
{
	char	*scop;
	size_t	i;

	i = 0;
	if ((scop = ft_strdup(src)))
	{
		while (scop[i])
		{
			if (scop[i] <= 32 || scop[i] > 126)
				scop[i] = '?';
			++i;
		}
		return (scop);
	}
	return (NULL);
}
