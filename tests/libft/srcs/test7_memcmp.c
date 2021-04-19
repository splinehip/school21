#include "../includes/test.h"

void	test7_memcpm(void)
{
	char	left[] = "hello world";
	char	rigth[] = "hello ford";

	printf("\nTest 7, memcmp, left: %s, rigth: %s, n: %d\n", left, rigth, 5);
	printf("Test 7, memcmp, res: %d\n", memcmp(left, rigth, 5));
	printf("Test 7.1, memcmp, n: 11, res: %d\n", memcmp(left, rigth, 11));

	printf("\nTest 7, ft_memcmp, left: %s, rigth: %s, n: %d\n", left, rigth, 5);
	printf("Test 7, ft_memcmp, res: %d\n", memcmp(left, rigth, 5));
	printf("Test 7.1, ft_memcmp, n: 11, res: %d\n", memcmp(left, rigth, 11));
}
