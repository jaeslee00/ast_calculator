/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:45:35 by aamadori          #+#    #+#             */
/*   Updated: 2019/02/07 00:08:48 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFT_H
# define _LIBFT_H
# include <sys/types.h>
# include <inttypes.h>
# include <string.h>
# include <wchar.h>
# include <stdlib.h>
# include <limits.h>

# define ANSI_COLOR_RED "\x1b[31m"
# define ANSI_COLOR_GREEN "\x1b[32m"
# define ANSI_COLOR_YELLOW "\x1b[33m"
# define ANSI_COLOR_BLUE "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN "\x1b[36m"
# define ANSI_COLOR_RESET "\x1b[0m"

# define ABS(x) ((x) >= 0 ? (x) : -(x))
# define MIN(x, y) ((x) < (y) ? (x) : (y))
# define MAX(x, y) ((x) >= (y) ? (x) : (y))
# define LST(lst, type) ((type*)(lst)->content)

typedef int			(*t_comparison)(const void *c1, const void *c2);
typedef int			(*t_int_comparison)(int c1, int c2);

typedef struct	s_buffer
{
	char	*buffer;
	size_t	index;
	size_t	size;
}				t_buffer;

int				ft_isupper(char c);
int				ft_islower(char c);
int				ft_max(int a, int b);
int				ft_min(int a, int b);
int				ft_isspace(char c);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putnstr(const char *str, size_t len);
void			ft_putendl(char const *s);
size_t			ft_strlen(const char *s);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *hay, const char *needle, size_t len);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_isprint(int c);
int				ft_isascii(int c);
int				ft_isalnum(int c);
int				ft_atoi(const char *str);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			ft_free_stub(void *ptr, size_t stub);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_itoa(int n);
void			ft_putnbr(int n);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
void			ft_splitdel(char **split);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			*ft_itoa_base(int number, const char *base);
ssize_t			ft_readbuff(int fd, char *buf, size_t len);
int				ft_witomb(char *str, wchar_t wc);
double			ft_sqrt(double num);

#endif
