/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 19:13:25 by avallete          #+#    #+#             */
/*   Updated: 2016/08/03 12:58:50 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Fill the str with the char c. Add a '\0' at end.
*/

void	ft_strfill(char *str, char c, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		str[i] = c;
		++i;
	}
	str[i] = '\0';
}
