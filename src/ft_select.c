/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 23:26:06 by avallete          #+#    #+#             */
/*   Updated: 2016/08/06 03:57:26 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	check_empty_arguments(int *argc, char ***argv)
{
	while (**argv && !***argv)
	{
		*argv += 1;
		*argc -= 1;
	}
}

static void	ft_init_sig(t_signal *sig_struct, t_select *env)
{
	sig_struct->data = env;
	ft_sig_handler_init(sig_struct->sig_handler);
	sig_struct->sig_handler[SIGINT] = &ft_quit;
	sig_struct->sig_handler[SIGWINCH] = &ft_update_term_infos;
	sig_struct->sig_handler[SIGTSTP] = &sigtstp_handle;
	sig_struct->sig_handler[SIGCONT] = &ft_init_term;
	ft_signal_watch(sig_struct);
}

static void	ft_select(char **argv)
{
	t_signal	sig_struct;
	t_select	env;

	env.debug = 0;
	ft_new_select(&env, argv);
	ft_init_sig(&sig_struct, &env);
	assign_colors(env.args);
	env.page.relpos = get_current_element_relative_position(\
														&(env.page), env.win);
	while (!env.quit)
	{
		if (env.print)
		{
			change_selected_element(&env);
			ft_print_all_page(&env);
			get_input(&env);
		}
	}
	ft_quit(&env);
}

int			main(int argc, char **argv)
{
	if (getenv("TERM") != NULL)
	{
		if (argc > 1)
		{
			--argc;
			++argv;
			check_empty_arguments(&argc, &argv);
			if (argc)
				ft_select(argv);
		}
	}
	return (0);
}
