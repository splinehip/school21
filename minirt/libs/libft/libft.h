/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:01:50 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/27 11:07:22 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define __ULLINT_TYPE__ unsigned long long int
# define __LINT_TYPE__ long int
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>

# ifdef __APPLE__
#  define MAC_OS 1
# else
#  define MAC_OS 0
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

typedef __ULLINT_TYPE__	t_ulli;
typedef __LINT_TYPE__	t_lint;

void	*ft_memset(void *buf, int c, size_t l);
void	ft_bzero(void *buf, size_t l);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *dest, int c, size_t n);
int		ft_memcmp(const void *left, const void *rigth, size_t n);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t l);
size_t	ft_strlcat(char *dest, const char *src, size_t n);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strnstr(const char *str, const char *substr, size_t n);
int		ft_strncmp(const char *str_1, const char *str_2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *str);
t_lint	ft_atol(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	*ft_calloc(size_t n, size_t size);
char	*ft_strdup(const char *str);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strtrim(const char *s1, const char *set);
char	**ft_split(const char *s, char c);
void	ft_sort_strs(char ***strs);
char	*ft_itoa(int n);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void	ft_putchar_fd(const char c, int fd);
void	ft_putstr_fd(const char *s, int fd);
void	ft_putendl_fd(const char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strjoinchr(char *res, char c);
t_ulli	ft_uintpow(int nb, int pow);
char	*ft_tobase(unsigned int base, unsigned int tobase, ...);
char	*ft_strljoinchr(char *res, char c);
void	ft_strtolower(char **str);
char	*ft_uitoa(unsigned int n);
void	*ft_xcalloc(size_t n, size_t size);
void	*ft_xmalloc(size_t size);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

typedef struct s_args
{
	int			p;
	long int	w;
	char		*res;
	size_t		len;
	size_t		old_len;
	size_t		align_left;
}				t_args;

int		ft_printf(const char *s, ...);
void	ft_printf_get_conversions(const char *s, t_args *args, va_list ap);
void	ft_printf_update_args_res(t_args *args, const char *s, int code);
void	ft_printf_apply_handlers(t_args *args, const char *ssi, va_list ap);
void	ft_printf_wp_handler(t_args *args, const char *ssi, va_list ap);
char	*ft_printf_flag_handler(t_args *args, const char *ssi, va_list ap);
void	ft_printf_c_handler(t_args *args, const char *ssi, va_list ap);
void	ft_printf_s_handler(t_args *args, const char *ssi, va_list ap);
void	ft_printf_diu_handler(t_args *args, const char *ssi, va_list ap);
void	ft_printf_p_handler(t_args *args, const char *ssi, va_list ap);
void	ft_printf_xx_handler(t_args *args, const char *ssi, va_list ap);
void	ft_printf_prc_handler(t_args *args, const char *ssi, va_list ap);

typedef struct s_vars
{
	int		i;
	int		j;
	int		fd;
	int		res;
	int		_return;
	size_t	k;
	char	*buf;
}			t_vars;

int		ft_gnl(int fd, char **line);
void	*ft_free(void *_p1, void *_p2);

#endif
