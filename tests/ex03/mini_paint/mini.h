# ifndef MINI_H
# define MINI_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <math.h>

typedef struct s_args
{
	int		width;
	int		height;
	char	bg;
	char	*map;
	float	x;
	float	y;
	float	r;
	float	d;
	char	style;
	char	smb;
}	t_args;

int	main(int argc, char **argv);

# endif
