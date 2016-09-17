/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstartby.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 17:05:25 by avallete          #+#    #+#             */
/*   Updated: 2016/08/25 16:26:36 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
**					Check if str start with niddle.
**					Return 0 if it does.
*/

int					ft_strstartby(const char *str, const char *niddle)
{
	if (ft_strlen(str) < ft_strlen(niddle))
		return (-1);
	return (ft_strncmp(str, niddle, ft_strlen(niddle)));
}
