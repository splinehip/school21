#include "../includes/test.h"

int	test27_split(void)
{
	char	s[] = "     ";
	char	c = ' ';
	char	**res;
	int		i;

	printf("\nTest 27, split, str: %s | sep: %c\n", s, c);
	res = ft_split(s, c);
	if (res == NULL)
	{
		printf("Test 27, split **res is NULL\n");
		return (0);
	}
	if (*res == NULL)
	{
		printf("Test 27, split res[0] is NULL\n");
		free(res);
		return (0);
	}
	else
	{
		i = 0;
		while (res[i] != NULL)
		{
			printf("Test 27, split res %d: %s|len %ld\n",
					i, res[i], ft_strlen(res[i]));
			i++;
		}
		printf("Test 27, split, strcmp res is: %d\n", strcmp(res[0], "\0"));
		printf("Test 27, split, **res len: %d\n", i);
		i = 0;
		while (res[i] != NULL)
			free(res[i++]);
		free(res);
		return (0);
	}
}
