/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cursor_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 02:15:55 by avallete          #+#    #+#             */
/*   Updated: 2016/08/06 02:16:28 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	init_cursor_position(t_select *env)
{
	env->page.pos.x = 0;
	env->page.pos.y = 0;
	env->page.pos.z = 0;
}
