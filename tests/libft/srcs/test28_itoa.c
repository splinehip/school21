#include "../includes/test.h"

void	test28_itoa(void)
{
	int		n;
	char	*res2;
	char	res[66];

	n = 30723140;
	printf("\nTest 28, itoa, n: %d\n", n);
	itoa(n, res, 10);
	printf("Test 28, itoa, res: %s\n", res);
	printf("Test 28, itoa, res len: %ld\n", ft_strlen(res));

	printf("\nTest 28, ft_itoa, n: %d\n", n);
	res2 = ft_itoa(n);
	printf("Test 28, ft_itoa, res: %s\n", res2);
	printf("Test 28, ft_itoa, res len: %ld\n", ft_strlen(res2));
	free(res2);
}
