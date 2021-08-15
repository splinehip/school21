#include "gnl.c"

int	main(void)
{
	int		res;
	char	*line;

	line = NULL;
	res = gnl(&line);
	while (res > 0)
	{
		printf("%s\n", line);
		if (line != NULL)
			free(line);
		res = gnl(&line);
		printf("RES: %i\n", res);
	}
	if (line != NULL)
		free(line);
	return (res);
}
