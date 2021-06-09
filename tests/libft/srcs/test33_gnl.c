#include "../includes/test.h"

void	test33_gnl(int argc)
{
	int		fd;
	int		fd2;
	int		res;
	char	*line;

	fd = 0;
	fd2 = 0;
	if (argc == 1)
	{
		fd = open("/home/oleg/Документы/git/school21/tests/ft_gnl_test/test.txt", O_RDONLY);
		fd2 = open("./Makefile", O_RDONLY);
	}
	if (fd != -1 && fd2 != -1)
	{
		while (1)
		{
			res = ft_gnl(fd, &line);
			if (res >= 0)
			{
				printf("RES success: %d\n", res);
				if (line != NULL)
				{
					printf("%s\n", line);
					printf("LINE_LEN: %ld\n", ft_strlen(line));
				}
				free(line);
			}
			res = ft_gnl(fd2, &line);
			if (res >= 0)
			{
				printf("RES success: %d\n", res);
				if (line != NULL)
				{
					printf("%s\n", line);
					printf("LINE_LEN: %ld\n", ft_strlen(line));
				}
				free(line);
			}
			if (res > 0)
				continue ;
			else if (res < 0)
			{
				printf("\nRES false: %d\n", res);
				if (line != NULL)
					printf("LINE_LEN: %ld\n", ft_strlen(line));
				else
					printf("LINE is NULL\n");
				break ;
			}
			else
				break ;
		}
		close(fd);
		close(fd2);
	}
	else
		printf("File open error!\n");
}
