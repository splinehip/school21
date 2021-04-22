#include "../includes/test.h"

void	test28_itoa(void)
{
	int		n;
	char	*res;

	n = 2147483647;
	printf("\nTest 28, ft_itoa, n: %d\n", n);
	res = ft_itoa(n);
	printf("Test 28, ft_itoa, res: %s\n", res);
	printf("Test 28, ft_itoa, res len: %ld\n", ft_strlen(res));
	free(res);

	n = -2147483648;
	printf("\nTest 28, ft_itoa, n: %d\n", n);
	res = ft_itoa(n);
	printf("Test 28, ft_itoa, res: %s\n", res);
	printf("Test 28, ft_itoa, res len: %ld\n", ft_strlen(res));
	free(res);
}
