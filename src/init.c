/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/30 00:52:17 by avallete          #+#    #+#             */
/*   Updated: 2015/05/30 01:57:15 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void     take_arguments(char **av, t_dlst **dest)
{
    if (av && *av)
    {
        *dest = ft_dlstnew(ft_strdup(*av), ft_strlen(*av));
        av++;
        while (*av)
        {
            ft_dlstpushback(dest, ft_dlstnew(ft_strdup(*av), ft_strlen(*av)));
            av++;
        }
    }
}

t_select        *structinit(char **av, int ac)
{
    t_select *ret;

    if ((ret = (t_select*)malloc(sizeof(t_select))))
    {
        ret->argsize = ac;
        ret->nameterm = getenv("TERM");
        take_arguments(av, &ret->args);
         if (tgetent(NULL, ret->nameterm) == ERR)
            ft_putstr("tgetent failed !\n"), exit(-1);
        if (tcgetattr(0, ret->termold) == -1 || tcgetattr(0, ret->term) == -1)
            ft_putstr("tcgetattr failed !\n"), exit(-1);
    }
    return (ret);
}