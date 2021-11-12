# include "mini_paint.h"

void	draw_cicle(t_mini_paint *args)
{
	int	x;
	int	y;

	y = 0;
	while (y < args->height)
	{
		x = 0;
		while (x < args->width)
		{
			args->d = sqrtf(powf(x - args->x, 2)
				+ powf(y - args->y, 2)) - args->r;
			if (args->d <= 0.00000000)
			{
				if (args->d > -1.00000000
					|| (args->d <= -1.00000000
						&& args->style == 'C'))
					args->map[x + y * args->width] = args->smb;
			}
			x++;
		}
		y++;
	}

}

int	draw_map(FILE *f, t_mini_paint *args)
{
	int	i;
	int	res;

	args->map = malloc(args->width * args->height * sizeof(char));
	if (args->map == NULL)
	{
		free(args->map);
		return (1);
	}
	memset(args->map, args->bg, args->width * args->height * sizeof(char));
	res = 0;
	while(fscanf(f, "%['c', 'C'] %f %f %f %c\n", &args->style,
		&args->x, &args->y, &args->r,
		&args->smb) == 5)
	{
		if (args->r <= 0.00000000)
		{
			free(args->map);
			return (1);
		}
		draw_cicle(args);
		res = 1;
	}
	if (res)
	{
		i = 0;
		while (i < args->height)
		{
			write(1, &args->map[i * args->width], args->width);
			write(1, "\n", 1);
			i++;
		}
		res = 0;
	}
	free(args->map);
	fclose(f);
	return (res);
}

int	argv_handler(char *file)
{
	FILE			*f;
	t_mini_paint	args;
	char			c[10];

	f = fopen(file, "r");
	if (f == NULL)
	{
		printf("Error: Operation file corrupted\n");
		return (1);
	}
	if ((fscanf(f, "%d %d %c%[$\n]",
		&args.width, &args.height, &args.bg, &c[0]) != 4))
	{
		fclose(f);
		printf("Error: Operation file corrupted\n");
		return (1);
	}
	if (args.width <= 0 || args.width > 300 || args.height <= 0
		|| args.height > 300)
	{
		fclose(f);
		printf("Error: Operation file corrupted\n");
		return (1);
	}
	return (draw_map(f, &args));
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Error: argument\n");
		return (1);
	}
	return (argv_handler(argv[1]));
}
