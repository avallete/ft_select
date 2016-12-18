/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 16:11:38 by avallete          #+#    #+#             */
/*   Updated: 2016/09/18 00:21:33 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void			bufferize(char **dest, char *content)
{
	char *ret;

	ret = NULL;
	ret = ft_strjoin(*dest, content);
	ft_secfree(*dest);
	*dest = ret;
}

static	char		*get_line(char **buf)
{
	char *truncbuf;
	char *linepos;
	char *ret;

	truncbuf = NULL;
	ret = NULL;
	if (*buf)
	{
		linepos = ft_strchr(*buf, '\n');
		if (linepos)
		{
			*linepos = '\0';
			truncbuf = ft_strdup(linepos + 1);
		}
		ret = ft_strdup(*buf);
		ft_secfree(*buf);
		*buf = truncbuf;
	}
	return (ret);
}

int					get_next_line(int const fd, char **line)
{
	int				f;
	char			tmpbuf[BUFF_SIZE + 1];
	static char		*buf = NULL;

	if (fd < 0 || (!(line)) || BUFF_SIZE < 1)
		return (-1);
	tmpbuf[BUFF_SIZE] = '\0';
	while ((!(ft_strchr(buf, '\n'))) && ((f = read(fd, tmpbuf, BUFF_SIZE)) > 0))
	{
		tmpbuf[f] = 0;
		bufferize(&buf, (char*)(tmpbuf));
	}
	if (f < 0)
		return (-1);
	*line = get_line(&buf);
	if (buf)
		return (1);
	return (0);
}
