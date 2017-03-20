/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 19:51:49 by avallete          #+#    #+#             */
/*   Updated: 2017/03/20 18:18:52 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include <get_next_line.h>
# include <libft.h>
# include <ft_bufferize.h>
# include <ft_signal.h>
# include <termios.h>
# include <term.h>
# include <sys/ioctl.h>
# include <signal.h>
# define IS_SELECTED		1
# define IS_HOVERED			2
# define IS_CFILE			4
# define IS_HFILE			8
# define IS_PAGE			16
# define LIGHT_BLUE_COLOR	"\e[1;36m"
# define LIGHT_RED_COLOR	"\e[1;31m"
# define LIGHT_GREEN_COLOR	"\e[1;32m"
# define LIGHT_PURPLE_COLOR	"\e[1;35m"
# define KEY_DOWN			"\E[B"
# define KEY_CTRL_Z			"\x1A\n"
# define KEY_UP				"\E[A"
# define KEY_RIGHT			"\E[C"
# define KEY_LEFT			"\E[D"
# define KEY_ESCAPE			"\E"
# define KEY_SPACE			" "
# define KEY_ENTER			"\n"
# define KEY_D				"d"
# define KEY_MAJ_D			"D"
# define KEY_BACKSPACE		"\x7F"
# define KEY_DELETE			"\E[3~"

typedef struct				s_elem
{
	char					*origname;
	char					*name;
	char					mode;
	char					*color;
	size_t					len;
}							t_elem;

typedef struct				s_column
{
	size_t					column_len;
	unsigned int			column_nb;
}							t_column;

typedef struct				s_vect
{
	unsigned int			x;
	unsigned int			y;
	unsigned int			z;
}							t_vect;

typedef struct				s_page
{
	t_dlst					*current_element;
	t_dlst					*start_page_element;
	struct s_column			columns_infos;
	unsigned int			arguments;
	t_vect					pos;
	t_vect					relpos;
	unsigned int			max_row;
	unsigned int			page_offset;
	unsigned int			elems_per_page;
	unsigned int			range_min;
	unsigned int			range_max;
}							t_page;

typedef struct				s_select
{
	void					*sig_action[255];
	struct termios			termold;
	struct termios			term;
	struct winsize			win;
	t_page					page;
	t_dlst					*args;
	char					*nameterm;
	char					quit;
	char					wait;
	char					buf[5];
	char					print;
	char					restore_term;
}							t_select;

void						elem_destructor(void *elem);
void						ft_get_win_size(t_select *env);
void						ft_window_too_small(t_select *env);
void						ft_clean_screen(t_select *env);

/*
** Init functions
*/
void						ft_init_term(void *data);
void						ft_new_select(t_select *env, char **argv);
void						test_terminal_capabilities(t_select *env);
char						*escape_parameter(const char *src);

/*
** Use termcaps
*/
void						ft_usetermcap(char *capacity, int fd);

/*
** Signal handling functions
*/
void						select_fatal_error(t_select *env, char *msg);
void						sigtstp_handle(void *data);
void						ft_quit(void *term);
void						ft_terminate(void *term);
void						ft_update_term_infos(void *env);

/*
** Delete functions
*/

void						delete_all(t_dlst *dlst);
void						delete_current_element(t_select *env);
void						delete_selected_elements(t_select *env);
void						delete_element(t_select *env, t_dlst *elem);

/*
** Input functions
*/

void						get_input(t_select *env);

/*
** Pagination functions
*/

int							ft_use_pagination(t_select *env, t_page *page);

/*
** Get elements functions
*/

t_vect						get_element_position_from_index(unsigned int index,\
															t_page *page);
t_vect						get_current_element_relative_position(t_page *page,\
															struct winsize win);
void						get_next_element(t_select *env);

/*
** Selected Elements functions
*/
void						change_selected_element(t_select *env);
int							is_selected_elements(t_select *env);
void						print_selected_elements(t_dlst *args);

/*
** ----------------------
**    Print Functions
** ----------------------
**
** Print element functions
*/

void						print_element(t_select *env, t_elem *elem);
void						ft_print_current_elem(t_select *env);

void						print_selected_elements(t_dlst *args);
int							is_selected_elements(t_select *env);

/*
** Print all page
*/

void						reprint_all_window(t_select *env);
void						ft_print_all_page(t_select *env);

/*
** Utils functions
*/

void						assign_colors(t_dlst *list);
void						init_cursor_position(t_select *env);
void						ft_usetermcap(char *capacity, int fd);
void						ft_get_columns_infos(
								t_dlst *args, t_page *page, struct winsize win);
void						ft_smarttrim(char *str, size_t max_len);
int							ft_use_pagination(t_select *env, t_page *page);
t_vect						get_element_position_from_index(unsigned int index,\
															t_page *page);
t_vect						get_current_element_relative_position(t_page *page,\
															struct winsize win);
void						ft_print_current_elem(t_select *env);
#endif
