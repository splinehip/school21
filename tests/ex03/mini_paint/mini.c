# include "mini.h"

void	draw_cicle(t_args *args)
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
					|| (args->d <= -1.00000000 && args->style == 'C'))
					args->map[x + y * args->width] = args->smb;
			}
			x++;
		}
		y++;
	}

}

int	draw_map(FILE *f, t_args *args)
{
	int	i;
	int	res;

	args->map = malloc(args->width * args->height * sizeof(char));
	if (args->map == NULL)
	{
		fclose(f);
		return (1);
	}
	memset(args->map, args->bg, args->width * args->height * sizeof(char));
	while((res = fscanf(f, "%['c', 'C'] %f %f %f %c ", &args->style,
		&args->x, &args->y, &args->r, &args->smb)) == 5)
	{
		if (args->r <= 0.00000000)
		{
			fclose(f);
			free(args->map);
			printf("Error: Operation file corrupted\n");
			return (1);
		}
		draw_cicle(args);
	}
	if (res < 0)
	{
		i = 0;
		while (i < args->height)
		{
			write(1, &args->map[i * args->width], args->width);
			write(1, "\n", 1);
			i++;
		}
		fclose(f);
		free(args->map);
		return (0);
	}
	fclose(f);
	free(args->map);
	printf("Error: Operation file corrupted\n");
	return (1);
}

int	main(int argc, char **argv)
{
	FILE	*f;
	t_args	args;

	if (argc != 2)
	{
		printf("Error: argument\n");
		return (1);
	}
	f = fopen(argv[1], "r");
	if (f == NULL)
	{
		printf("Error: Operation file corrupted\n");
		return (1);
	}
	if (fscanf(f, "%d %d %c\n",
		&args.width, &args.height, &args.bg) != 3)
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
