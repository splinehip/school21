#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	gnl(char **line);

static void join(char **line, char buf)
{
	int		size;
	char	*tmp;

	size = 0;
	while ((*line)[size++] != 0)
		;
	tmp = malloc((size + 1) * sizeof(char));
	size = 0;
	while ((*line)[size] != 0)
	{
		tmp[size] = (*line)[size];
		size++;
	}
	tmp[size] = buf;
	tmp[size + 1] = 0;
	free(*line);
	*line = tmp;
}


int gnl(char **line)
{
	int 	res;
	char	buf;

	*line = malloc(1 * sizeof(char));
	**line = 0;
	res = read(0, &buf, 1);
	while (res > 0)
	{
		if (buf == '\n')
			return (1);
		else
		{
			join(line, buf);
			res = read(0, &buf, 1);
		}
	}
	return (res);
}
