/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 22:38:25 by avallete          #+#    #+#             */
/*   Updated: 2015/05/30 02:04:41 by avallete         ###   ########.fr       */
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
typedef struct          s_select
{
    t_dlst              *args;
    int                 argsize;
    struct termios      termold;
    struct termios      term;
    char                *nameterm;
}                       t_select;

t_select        *structinit(char **av, int ac);
#endif