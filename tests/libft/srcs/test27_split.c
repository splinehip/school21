#include "../includes/test.h"

int	test27_split(void)
{
	char	s[] = ",,,Hello,,Pushkin!,,World,,,";
	char	c = ',';
	char	**res;
	int		i;

	printf("\nTest 27, split, str: %s | sep: ','\n", s);
	res = ft_split(s, c);
	if (res == NULL)
	{
		printf("Test 27, split res is NULL\n");
		return (0);
	}
	i = 0;
	while (res[i] != NULL)
	{
		printf("Test 27, split res %d: %s\n", i, res[i]);
		i++;
	}
	printf("Test 27, split, res len: %d\n", i);
	i = 0;
	while (res[i] != NULL)
	{
		free(res[i++]);
	}
	free(res);
	return (0);
}
