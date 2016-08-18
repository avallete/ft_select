/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 03:49:31 by avallete          #+#    #+#             */
/*   Updated: 2016/08/06 03:50:28 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	assign_colors(t_dlst *list)
{
	while (list)
	{
		if (!ft_strendby(((t_elem*)list->content)->name, ".o"))
			((t_elem*)list->content)->color = LIGHT_BLUE_COLOR;
		if (!ft_strendby(((t_elem*)list->content)->name, ".c"))
			((t_elem*)list->content)->color = LIGHT_RED_COLOR;
		if (!ft_strendby(((t_elem*)list->content)->name, ".h"))
			((t_elem*)list->content)->color = LIGHT_GREEN_COLOR;
		if (!ft_strendby(((t_elem*)list->content)->name, ".a"))
			((t_elem*)list->content)->color = LIGHT_PURPLE_COLOR;
		list = list->next;
	}
}
