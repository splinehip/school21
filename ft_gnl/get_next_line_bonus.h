#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif
# include <unistd.h>
# include <stdlib.h>

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

int		get_next_line(int fd, char **line);
void	*ft_calloc(size_t n, size_t size);
void	*ft_memset(void *buf, int c, size_t l);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *str);
void	*_free(void *_p1, void *_p2);

#endif
