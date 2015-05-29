/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 22:37:39 by avallete          #+#    #+#             */
/*   Updated: 2015/05/29 20:49:07 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void    ft_select(char **env, char **av, int ac)
{
    if (env && ac)
    {
        (void)env;
        (void)ac;
    }
    t_dlst *test;
    if (*av)
        test = ft_dlstnew(ft_strdup(*av), ft_strlen(*av));
    av++;
    while (*av)
    {
        ft_dlstpushback(&test, ft_dlstnew(ft_strdup(*av), ft_strlen(*av)));
        av++;
    }
    ft_circlelist(&test);
    ft_printf("%s\n", (char*)test->content);
    ft_dlstdelone(&(test->next->next));
    while (test)
    {
        ft_printf("%s\n", (char*)test->content);
        test = test->next;
    }
}

int     main(int argc, char **argv, char **env)
{
    if (argc >= 2)
        ft_select(env, argv, argc);
    return (0);
}