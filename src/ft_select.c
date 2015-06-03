/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 22:37:39 by avallete          #+#    #+#             */
/*   Updated: 2015/06/03 17:05:12 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int sig;

void    printcontent(t_dlst *elem)
{
    ft_putstr(((t_elem*)elem->content)->name);
    ft_putchar('\n');
}

void    get_size(t_select *select)
{
    ioctl(0, TIOCGWINSZ, &(select->win));
    ft_printf("size = %d:%d\n", select->win.ws_row, select->win.ws_col);
}

void    get_touch(t_select *select)
{
    get_size(select);
    read(0, select->buf, 3);
    ft_putnbr((int)select->buf[0]);
    ft_putchar('\n');
    ft_putnbr((int)select->buf[1]);
    ft_putchar('\n');
    ft_putnbr((int)select->buf[2]);
    ft_putchar('\n');
}

static void    quit_prog(t_select *select)
{
    tcsetattr(0, TCSANOW, &(select->termold));
    select->quit = 1;
}

void    sig_handler(int signal)
{
    sig = signal;
}

void    sig_action(t_select *select)
{
    if (sig)
    {
        ft_printf("Signal is : %d\n", sig);
        if (sig == SIGWINCH)
        {
            get_size(select);
        }
        sig = 0;
    }
}

void    ft_select(char **av, int ac)
{
    t_select *select;

    select = NULL;
    select = structinit(av, ac);
    signal(SIGINT, &sigquit);
    signal(SIGWINCH, &sig_handler);
    while (!select->quit)
    {
        sig_action(select);
        get_touch(select);
        if (select->buf[0] == 4)
            quit_prog(select);
        clear_term();
        ft_dlstiter(select->args, printcontent);
    }
}

int     main(int argc, char **argv)
{
    sig = 0;
    if (getenv("TERM") != NULL)
    {
        if (argc >= 2)
            ft_select(++argv, argc);
    }
    return (0);
}