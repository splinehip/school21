# ifndef MINI_PAINT_H
# define MINI_PAINT_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <math.h>

typedef struct s_mini_paint
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
}	t_mini_paint;

# endif
