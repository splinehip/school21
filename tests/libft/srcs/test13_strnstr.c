#include "../includes/test.h"

void	test13_strnstr(void)
{
	char	str[] = "hello world";
	char	substr[] = "llo";

	printf("\nTest 13, strnstr, str: %s, substr: %s\n", str, substr);
	printf("Test 13, strnstr, res: %c\n", *strnstr(str, substr, 6));

	printf("\nTest 13, ft_strnstr, str: %s, substr: %s\n", str, substr);
	printf("Test 13, ft_strnstr, res: %c\n", *ft_strnstr(str, substr, 6));
}
