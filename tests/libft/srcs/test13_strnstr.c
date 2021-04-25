#include "../includes/test.h"

void	test13_strnstr(void)
{
	char	str[] = "hello world";
	char	substr[] = "llo";

	char *s1 = "MZIRIBMZIRIBMZE123";
	char *s2 = "MZIRIBMZE";
	size_t max = strlen(s2);
	char *i1 = strnstr(s1, s2, max);
	char *i2 = ft_strnstr(s1, s2, max);

	printf("\nTest 13, strnstr, ft_strnstr s1: %s, s2: %s, max: %ld\n", s1, s2, max);
	printf("Test 13, strnstr res: %s\n", i1);
	printf("Test 13, ft_strnstr res: %s\n", i2);

	printf("\nTest 13, strnstr, str: %s, substr: %s\n", str, substr);
	printf("Test 13, strnstr, res: %s\n", strnstr(str, substr, 6));

	printf("\nTest 13, ft_strnstr, str: %s, substr: %s\n", str, substr);
	printf("Test 13, ft_strnstr, res: %s\n", ft_strnstr(str, substr, 6));
}
