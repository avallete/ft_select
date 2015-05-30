/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 22:37:39 by avallete          #+#    #+#             */
/*   Updated: 2015/05/30 02:04:43 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void    printcontent(t_dlst *elem)
{
    ft_putstr((char*)elem->content);
    ft_putchar('\n');
}

void    ft_select(char **av, int ac)
{
    t_select *select;

    select = NULL;
    select = structinit(av, ac);
    if (select)
        ft_dlstiter(select->args, &printcontent);
}

int     main(int argc, char **argv)
{
    if (getenv("TERM") != NULL)
    {
        if (argc >= 2)
            ft_select(++argv, argc);
    }
    return (0);
}