#include <fcntl.h>
#include <stdio.h>

#include "../../ft_gnl/get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		fd2;
	int		res;
	int		i;
	char	*line;

	(void)argv;
	i = 0;
	fd = 0;
	fd2 = 0;
	line = NULL;
	if (argc == 1)
	{
		fd = open("../../ft_gnl/gnlTester/files/empty", O_RDONLY);
		//fd2 = open("../../ft_gnl/gnlTester/files/multiple_line_with_nl", O_RDONLY);
		//fd = open("/home/oleg/Документы/git/school21/tests/ft_gnl_test/test.txt", O_RDONLY);
		//fd2 = open("./Makefile", O_RDONLY);
		//fd = 1000;
	}
	fd2 = fd;
	if (fd != -1 && fd2 != -1)
	{
		while (1)
		{
			i++;
			if (i % 2 == 0)
				res = get_next_line(fd, &line);
			else
				res = get_next_line(fd2, &line);
			if (res >= 0)
			{
				printf("RES success: %d\n", res);
				if (line != NULL)
				{
					printf("%s\n", line);
					printf("LINE_LEN: %ld\n", ft_strlen(line));
				}
				if (i < 2)
					continue ;
				else
					break ;
			}
			else if (res < 0)
			{
				printf("\nRES false: %d\n", res);
				if (line != NULL)
					printf("LINE_LEN: %ld\n", ft_strlen(line));
				else
					printf("LINE is NULL\n");
				break ;
			}
		}
		close(fd);
		close(fd2);
	}
	else
		printf("File open error!\n");
	if (line != NULL)
		free(line);
}
