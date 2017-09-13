/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <mpaincha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:29:31 by mpaincha          #+#    #+#             */
/*   Updated: 2016/01/14 16:59:14 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define BUFF_SIZE 4096
# define LINESS (((t_lines *)(tmp->content))->lines)

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
typedef struct		s_elem
{
	void			*content;
	struct s_elem	*prev;
	struct s_elem	*next;
}					t_elem;
typedef struct		s_dbllist
{
	size_t			length;
	struct s_elem	*head;
	struct s_elem	*tail;
}					t_dbllist;
typedef struct		s_lines
{
	char			*lines;
	int				fd;
}					t_lines;

int					clean_open(const char *path, int flag);
int					clean_read(int fildes, char *buf, size_t nbyte);
int					get_next_line(int const fd, char **line);
int					ft_atoi(const char *str);
intmax_t			ft_atoi_intmax(const char *str);
void				*ft_bzero(void *s, size_t n);
int					ft_count_words(char const *s, char c);
void				ft_free2dtab(void **tab, int tab_size);
size_t				ft_intlen(int n);
size_t				ft_intlenbase(int n, size_t base);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_islower(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_isupper(int c);
char				*ft_itoa(int n);
char				*ft_itoa_imax(intmax_t n);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void(*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdbladd(t_dbllist *list, void *content,
					size_t cont_size);
void				ft_lstdbladd_head(t_dbllist *list, void *content,
					size_t cont_size);
void				ft_lstdbladd_tail(t_dbllist *list, void *content,
					size_t cont_size);
void				ft_lstdbldel(t_dbllist **list);
t_dbllist			*ft_lstdblnew(void);
void				ft_putlsthead(t_dbllist *list);
void				ft_putlsttail(t_dbllist *list);
void				ft_lstdbldelone(t_dbllist **list, t_elem *to_remove);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const*s, int fd);
char				**ft_realloc(char **tab);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoinandfree(char *s1, char *s2, int tofree);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strrev(char *str);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_tolower(int c);
char				*ft_strtolower(char *str);
int					ft_toupper(int c);
#endif
