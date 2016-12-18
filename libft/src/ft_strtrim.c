/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:14:35 by avallete          #+#    #+#             */
/*   Updated: 2016/09/22 18:36:14 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	char	*result;
	int		b;
	int		len;
	int		mode;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	mode = -1;
	b = 0;
	if ((result = (char*)malloc((sizeof(char)) * (len + 1))))
	{
		while (ft_isspace(s[b]) && s[b] != '\0')
			b++;
		while (ft_isspace(s[len]) || s[len] == '\0')
			len--;
		while (b <= len)
		{
			result[++mode] = s[b];
			b++;
		}
		result[++mode] = '\0';
		return (result);
	}
	return (NULL);
}
