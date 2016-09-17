/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stroccur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 16:02:44 by avallete          #+#    #+#             */
/*   Updated: 2016/08/25 16:10:04 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int					ft_stroccur(const char *s1, const char *s2)
{
	char	*tmp;
	int		occurs;

	occurs = 0;
	tmp = (char*)s1;
	while ((tmp = ft_strstr(tmp, s2)))
		++occurs;
	return (occurs);
}
