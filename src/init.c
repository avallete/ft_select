/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/30 00:52:17 by avallete          #+#    #+#             */
/*   Updated: 2015/06/02 18:42:03 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_elem   *new_elem(char *name, char mode, int len)
{
    t_elem      *ret;

    if ((ret = (t_elem*)malloc(sizeof(t_elem))))
    {
        ret->name = ft_strdup(name);
        ret->mode = mode;
        ret->len = len;
    }
    return (ret);
}

static void     take_arguments(char **av, t_dlst **dest)
{
    if (av && *av)
    {
        *dest = ft_dlstnew(new_elem(*av, 0, ft_strlen(*av)), sizeof(t_elem*));
        av++;
        while (*av)
        {
            ft_dlstpushback(dest, ft_dlstnew(new_elem(*av, 0, ft_strlen(*av)),\
                sizeof(t_elem*)));
            av++;
        }
    }
}

void            clear_term()
{
    tputs(tgetstr("cl", NULL), 1, ft_putthat);
}

t_select        *structinit(char **av, int ac)
{
    t_select *ret;

    if ((ret = (t_select*)malloc(sizeof(t_select))))
    {
        ret->argsize = ac;
        ret->nameterm = getenv("TERM");
        take_arguments(av, &ret->args);
         if (tgetent(NULL, ret->nameterm) < 1)
            ft_putstr("tgetent failed !\n"), exit(-1);
        if (tcgetattr(0, &ret->termold) == -1 || tcgetattr(0, &ret->term) == -1)
            ft_putstr("tcgetattr failed !\n"), exit(-1);
        ret->term.c_lflag &= ~(ICANON | ECHO);
        if (tcsetattr(0, TCSADRAIN, &(ret->term)) == -1)
            ft_putstr("Changing terminal mode failed !\n"), exit(-1);
        ret->quit = 0;
        ret->buf[3] = 0;
        clear_term();
    }
    return (ret);
}