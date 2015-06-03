/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 04:53:37 by avallete          #+#    #+#             */
/*   Updated: 2015/05/31 05:04:06 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void sigquit(int sig)
{
    t_select *ret;

    if ((ret = (t_select*)malloc(sizeof(t_select))))
    {
        tcgetattr(0, &ret->termold);
        ret->termold.c_lflag = (ICANON | ECHO);
        tcsetattr(0, TCSANOW, &(ret->termold));
        if (sig == SIGINT)
        ft_putstr("Signal sigint catch\n");
        exit(100);
    }
}