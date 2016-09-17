/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stralcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/28 14:35:40 by avallete          #+#    #+#             */
/*   Updated: 2015/08/28 14:38:26 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_stralcmp(const char *s1, const char *s2)
{
	int i;
	int e;
	int f;

	i = 0;
	while (((unsigned char *)s1)[i] != '\0' && ((unsigned char *)s2)[i] != '\0')
	{
		e = ft_tolower(((unsigned char *)s1)[i]);
		f = ft_tolower(((unsigned char *)s2)[i]);
		if (e != f)
			return (e - f);
		i++;
	}
	return (e - f);
}
