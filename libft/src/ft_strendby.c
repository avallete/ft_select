/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strendby.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 15:30:37 by avallete          #+#    #+#             */
/*   Updated: 2016/08/30 19:01:24 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
**		Search if the end of str match with niddle.
**		Return 0 if match.
*/

int		ft_strendby(const char *str, const char *niddle)
{
	size_t size_str;
	size_t size_niddle;

	size_str = ft_strlen(str);
	size_niddle = ft_strlen(niddle);
	if (size_str < size_niddle)
		return (-1);
	while (size_niddle)
	{
		if (str[size_str--] != niddle[size_niddle--])
			return (1);
	}
	return (str[size_str] != niddle[size_niddle]);
}
