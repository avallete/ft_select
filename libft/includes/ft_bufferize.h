/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufferize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 14:16:54 by avallete          #+#    #+#             */
/*   Updated: 2016/06/15 14:39:00 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUFFERIZE_H
# define FT_BUFFERIZE_H
# include <libft.h>
# define BUFFERIZE_SIZE 60000

int ft_bufferize(int fd, char *str, char flush);
#endif
