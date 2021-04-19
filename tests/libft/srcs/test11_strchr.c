#include "../includes/test.h"

void	test11_strchr(void)
{
	char	str[] = "hello world";

	printf("\nTest 11, strchr, str: %s, char: w\n", str);
	printf("Test 11, strchr, res: %c\n", *strchr(str, 'w'));

	printf("\nTest 11, ft_strchr, str: %s, char: w\n", str);
	printf("Test 11, ft_strchr, res: %c\n", *ft_strchr(str, 'w'));
}
