/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 22:38:25 by avallete          #+#    #+#             */
/*   Updated: 2015/06/02 18:41:26 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
#define FT_SELECT_H
#include "get_next_line.h"
#include "libft.h"
#include "ft_printf.h"
#include <termios.h>
#include <term.h>
#include <sys/ioctl.h>
#include <signal.h>

extern int              sig;

typedef struct          s_elem
{
    char                *name;
    char                mode;
    int                 len;
}                       t_elem;

typedef struct          s_select
{
    t_dlst              *args;
    int                 argsize;
    struct termios      termold;
    struct termios      term;
    char                *nameterm;
    char                quit;
    char                buf[4];
    struct winsize      win;
}                       t_select;

t_select        *structinit(char **av, int ac);
int             ft_putthat(int c);
void            clear_term();
/*
** Signal handling functions
*/
void sigquit(int sig);
#endif