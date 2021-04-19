#include "../includes/test.h"

void	test12_strrchr(void)
{
	char	str[] = "hello world";

	printf("\nTest 12, strrchr, str: %s, char: w\n", str);
	printf("Test 12, strrchr, res: %c\n", *strrchr(str, 'w'));

	printf("\nTest 12, ft_strrchr, str: %s, char: w\n", str);
	printf("Test 12, ft_strrchr, res: %c\n", *ft_strrchr(str, 'w'));
}
