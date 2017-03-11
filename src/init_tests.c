/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 20:50:42 by avallete          #+#    #+#             */
/*   Updated: 2017/03/11 20:54:00 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	test_terminal_capabilities(t_select *env)
{
	if (tgetstr("ti", NULL) == NULL || tgetstr("vi", NULL) == NULL ||
			tgetstr("te", NULL) == NULL || tgetstr("ve", NULL) == NULL ||
			tgetstr("ho", NULL) == NULL || tgetstr("us", NULL) == NULL ||
			tgetstr("mr", NULL) == NULL || tgetstr("ue", NULL) == NULL ||
			tgetstr("me", NULL) == NULL || tgetstr("cm", NULL) == NULL ||
			tgetstr("DL", NULL) == NULL ||
			tgoto(tgetstr("DL", NULL), 0, 0) == NULL)
		select_fatal_error(env, "Error TERM doesn't have all capabilities.");
}
