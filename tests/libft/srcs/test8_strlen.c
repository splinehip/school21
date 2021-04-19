#include "../includes/test.h"

void	test8_strlen(void)
{
	char	str[] = "hello world";

	printf("\nTest 8, strlen, str: %s\n", str);
	printf("Test 8, strlen, res: %ld\n", strlen(str));

	printf("\nTest 8, ft_strlen, str: %s\n", str);
	printf("Test 8, ft_strlen, res: %ld\n", ft_strlen(str));
}
