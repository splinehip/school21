#include "../includes/test.h"

void	test22_calloc(void)
{
	char *str;

	str = (char *)calloc(11, sizeof(char));
	if (str != NULL)
	{
		ft_memset(str, '0', 10);
		str[10] = '\0';
		printf("\nTest 22, calloc, new str: %s\n", str);
	}
	else
	{
		printf("\nTest 22, calloc, new str is NULL\n");
	}
	free(str);

	str = (char *)ft_calloc(11, sizeof(char));
	if (str != NULL)
	{
		ft_memset(str, '0', 10);
		str[10] = '\0';
		printf("Test 22, ft_calloc, new str: %s\n", str);
	}
	else
	{
		printf("Test 22, ft_calloc, new str is NULL\n");
	}
	free(str);
}
