/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 23:13:48 by avallete          #+#    #+#             */
/*   Updated: 2017/03/11 20:53:14 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <stdio.h>

static t_elem			*ft_new_elem(char *ename, char emode, int elen)
{
	t_elem	*ret;

	if ((ret = (t_elem*)malloc(sizeof(t_elem))))
	{
		ret->name = ft_strdup(ename);
		ret->mode = emode;
		ret->len = (size_t)elen;
		ret->color = NULL;
	}
	return (ret);
}

static int				ft_save_arguments(char **argv, t_dlst **dest)
{
	int		i;
	t_elem	*first_elem;

	i = 0;
	if (argv && *argv)
	{
		first_elem = ft_new_elem(*argv, 0, ft_strlen(*argv));
		first_elem->mode = IS_HOVERED;
		*dest = ft_dlstnew(first_elem, sizeof(t_elem*));
		argv++;
		++i;
		while (*argv)
		{
			if (**argv)
			{
				ft_dlstpushback(dest, ft_dlstnew(ft_new_elem(*argv, 0,\
								ft_strlen(*argv)), sizeof(t_elem*)));
				++i;
			}
			argv++;
		}
	}
	return (i);
}

void					select_fatal_error(t_select *env, char *msg)
{
	if (msg)
		ft_putendl_fd(msg, STDERR_FILENO);
	env->quit = 1;
	ft_quit(env);
}

void					ft_init_term(void *data)
{
	t_select *env;

	env = (t_select*)data;
	env->print = 1;
	if (!isatty(STDIN_FILENO))
		select_fatal_error(env, "STDIN_FILENO does not valid terminal !");
	if (tgetent(NULL, env->nameterm) < 1)
		select_fatal_error(env, "tgetent failed !");
	if (tcgetattr(STDIN_FILENO, &env->termold) == -1\
			|| tcgetattr(STDIN_FILENO, &env->term) == -1)
		select_fatal_error(env, "tcgetattr failed !");
	env->restore_term = 1;
	env->term.c_iflag |= IGNBRK;
	env->term.c_lflag |= ISIG;
	env->term.c_lflag &= ~(ICANON | ECHO | ECHOK | ECHOE | ECHONL | IEXTEN);
	while (tcsetattr(STDIN_FILENO, TCSADRAIN, &(env->term)) == -1)
	{
	}
	test_terminal_capabilities(env);
	ft_usetermcap("ti", STDIN_FILENO);
	ft_usetermcap("vi", STDIN_FILENO);
	signal(SIGTSTP, &ft_sighandler);
	ft_update_term_infos(env);
}

void					ft_new_select(t_select *env, char **argv)
{
	env->wait = 0;
	env->restore_term = 0;
	env->nameterm = getenv("TERM");
	env->page.arguments = ft_save_arguments(argv, &env->args);
	env->page.current_element = env->args;
	env->page.start_page_element = env->args;
	init_cursor_position(env);
	env->quit = 0;
	ft_bzero(env->buf, 5);
	ft_init_term(env);
}
