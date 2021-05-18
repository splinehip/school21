#include "../includes/test.h"

void	test32_uitoa(void)
{
	unsigned int    n;
	char	    *res2;
	char	    res[66];

	n = -2;
	printf("\nTest 32, itoa, n: %d\n", n);
	itoa(n, res, 10);
	printf("Test 32, itoa, res: %s\n", res);
	printf("Test 32, itoa, res len: %ld\n", ft_strlen(res));

	printf("\nTest 32, ft_uitoa, n: %d\n", n);
	res2 = ft_uitoa(n);
	printf("Test 32, ft_uitoa, res: %s\n", res2);
	printf("Test 32, ft_uitoa, res len: %ld\n", ft_strlen(res2));
	free(res2);
}
