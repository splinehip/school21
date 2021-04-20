#include "../includes/test.h"

void	test14_strncmp(void)
{
	char	str_1[] = "hello world";
	char	str_2[] = "hello world";
	char	str_3[] = "hello";

	printf("\nTest 14, strncmp, str_1: %s, str_2: %s\n", str_1, str_2);
	printf("Test 14, strncmp, res: %d\n", strncmp(str_1, str_2, 12));
	printf("\nTest 14.1, strncmp, str_1: %s, str_2: %s, n: 6\n", str_1, str_2);
	printf("Test 14.1, strncmp, res: %d\n", strncmp(str_1, str_2, 6));
	printf("\nTest 14.2, strncmp, str_1: %s, str_2: %s, n: 6\n", str_1, str_3);
	printf("Test 14.2, strncmp, res: %d\n", strncmp(str_1, str_3, 6));

	printf("\nTest 14, ft_strncmp, str_1: %s, str_2: %s\n", str_1, str_2);
	printf("Test 14, ft_strncmp, res: %d\n", ft_strncmp(str_1, str_2, 12));
	printf("\nTest 14.1, ft_strncmp, str_1: %s, str_2: %s, n: 6\n",
																str_1, str_2);
	printf("Test 14.1, ft_strncmp, res: %d\n", ft_strncmp(str_1, str_2, 6));
	printf("\nTest 14.2, ft_strncmp, str_1: %s, str_2: %s, n: 6\n",
																str_1, str_3);
	printf("Test 14.2, ft_strncmp, res: %d\n", ft_strncmp(str_1, str_3, 6));
}
