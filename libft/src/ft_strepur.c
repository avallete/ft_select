/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strepur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 18:50:18 by avallete          #+#    #+#             */
/*   Updated: 2016/09/22 21:12:24 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	epur_len(const char *src)
{
	int		i;
	int		space_sequence;
	size_t	origin_len;

	i = 0;
	origin_len = ft_strlen(src);
	while (src[i])
	{
		++i;
		if (ft_isspace(src[i]))
		{
			space_sequence = 0;
			while (ft_isspace(src[i]))
			{
				++space_sequence;
				++i;
			}
			origin_len -= space_sequence;
		}
	}
	return (origin_len);
}

char			*ft_strepur(const char *src)
{
	size_t	newlen;
	int		i;
	int		e;
	char	*epured;

	i = 0;
	e = 0;
	epured = NULL;
	if (src && (newlen = epur_len(src)) && \
			(epured = ft_strnew(newlen + 1)))
	{
		while (src[i])
		{
			if (!(ft_isspace(src[i])))
				epured[e++] = src[i++];
			else
			{
				epured[e++] = ' ';
				while (ft_isspace(src[i]))
					++i;
			}
		}
		epured[e] = '\0';
	}
	return (epured);
}
