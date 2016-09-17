/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:41:36 by avallete          #+#    #+#             */
/*   Updated: 2014/11/14 11:23:25 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdup(const char *s)
{
	int		len;
	char	*scop;

	len = ((ft_strlen(s)) + 1);
	if ((scop = ((char*)malloc(sizeof(char) * len))))
	{
		ft_strcpy(scop, s);
		return (scop);
	}
	return (NULL);
}
