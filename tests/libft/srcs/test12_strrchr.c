#include "../includes/test.h"

void	test12_strrchr(void)
{
	char	str[] = "\0";
	char	*d1 = strrchr(str, 'w');
	char	*d2 = ft_strrchr(str, 'w');

	if (d1 != d2)
	{
		printf("\nTest 12, strrchr FAIL\n");
		if (d1)
			printf("Test 12, strrchr res: %c\n", *d1);
		else
			printf("Test 12, strrchr res: NULL\n");

		if (d2)
			printf("Test 12, ft_strrchr res: %c\n", *d2);
		else
			printf("Test 12, ft_strrchr res: NULL\n");
	}
	else
	{
		printf("\nTest 12, strrchr SUCCESS\n");
		if (d1)
			printf("Test 12, strrchr res: %c\n", *d1);
		else
			printf("Test 12, strrchr res: NULL\n");

		if (d2)
			printf("Test 12, ft_strrchr res: %c\n", *d2);
		else
			printf("Test 12, ft_strrchr res: NULL\n");
	}
}
