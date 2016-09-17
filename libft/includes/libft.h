/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:41:54 by avallete          #+#    #+#             */
/*   Updated: 2016/08/25 16:02:22 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# define FT_ABS(x)  (((x) < 0) ? -(x) : (x))

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_dlst
{
	void			*content;
	size_t			content_size;
	struct s_dlst	*next;
	struct s_dlst	*back;
}					t_dlst;

typedef struct		s_tree
{
	void			*content;
	size_t			content_size;
	struct s_tree	*father;
	struct s_tree	*left;
	struct s_tree	*right;
}					t_tree;

/*
** Str Functions
*/
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *s1, const char *s2, size_t size);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_stroccur(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s);
char				*ft_strndup(const char *s, size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
size_t				ft_strlen(const char *s);
char				*ft_strncpy(char *dest, const char *src, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_strendby(const char *str, const char *niddle);
int					ft_strstartby(const char *str, const char *niddle);
void				ft_strfill(char *str, char c, size_t len);

/*
** Write functions
*/
void				ft_filler(char c, size_t len);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_splitprint(char **split);
void				ft_putsterr(char *str);
void				ft_puterrdl(char *str);
void				ft_printtab(int *tab, int max);

/*
** Tree Functions
*/
t_tree				*ft_treenew(void *content, size_t content_size);
void				ft_nodeaddleft(t_tree *new, t_tree **tree);
void				ft_nodeaddright(t_tree *new, t_tree **tree);

/*
** Numbers functions
*/
size_t				ft_nbrlen(int nbr);
char				*ft_itoa(int n);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
int					ft_atoi(const char *str);

/*
** Char functions
*/
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);

/*
** Memory functions
*/
void				*ft_realloc(void *ptr, size_t size);
void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_realloc(void *ptr, size_t size);
void				*ft_calloc(size_t nmemb, size_t size);
void				ft_secfree(void *ptr);

/*
** List functions
*/
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstpushback(t_list **alst, t_list *new);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstlast(t_list *begin_list);
size_t				ft_lstsize(t_list *list);

/*
** Double linked list functions
*/
t_dlst				*ft_dlstnew(void *content, size_t content_size);
t_dlst				*ft_dlst_get_elem_index(t_dlst *lst, unsigned int index);
void				ft_dlstadd(t_dlst **lst, t_dlst *new);
void				ft_dlstdelone(t_dlst **lst, void(*destructor)(void *));
void				ft_dlstpushback(t_dlst **lst, t_dlst *new);
void				ft_dlstiter(t_dlst *list, void (*f)(t_dlst *elem));
void				ft_circlelist(t_dlst **list);
size_t				ft_dlst_content_len(t_dlst *lst, size_t(*len_count)(void*));
size_t				ft_dlst_content_max(t_dlst *lst, size_t(*len_count)(void*));
int					ft_dlst_get_node_index(t_dlst *list_begin, t_dlst *node);

/*
** Split functions
*/
int					ft_tabstrcmp(char **tab, char *str, size_t size);
char				**ft_strsplit(char const *s, char c);
size_t				ft_splitlen(char **env);
void				ft_splitdel(char **split);
char				**ft_resizesplit(char **src, size_t begin, size_t end);
void				split_iter(char **split, void *(*f)(char *str));
#endif
