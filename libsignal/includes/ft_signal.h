/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 19:34:38 by avallete          #+#    #+#             */
/*   Updated: 2016/06/24 17:57:01 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SIGNAL_H
# define FT_SIGNAL_H
# define UNIX_SIG_LEN 33
# include <signal.h>

/*
** A syntactic sugar for functions pointers who manages the signal actions.
*/
typedef	void		(*t_func_handler)(void *);

/*
** This structure contain all necessary data for the library
**     |*data:			The pointer to the "context" data of your programm
**     |               	This data will be sent to your "sig_handler" function
**     |               	as first and uniq argument.
**     |
**     |sig_handler:	The array of function pointer who handle each signal.
**     |               	If a signal is unhandled it must be set to NULL.
**     |               	This function must have this kind of prototype:
**     |               	```void sigint_handler(void *data)```
*/

typedef struct		s_signal
{
	void			*data;
	t_func_handler	sig_handler[UNIX_SIG_LEN];
}					t_signal;

t_signal			*ft_get_signal_data(t_signal *env);
void				ft_parse_signal(t_signal *env, int signal);
void				ft_signal_watch(t_signal *env);
void				ft_sig_handler_init(t_func_handler handlers[UNIX_SIG_LEN]);
void				ft_sighandler(int signal);
#endif
