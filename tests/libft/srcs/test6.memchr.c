#include "../includes/test.h"

void	test6_memchr(void)
{
	char	src[] = "hello world";
	char	c = 'w';

	printf("\nTest 6, memchr: src: %s, char: %c\n", src, c);
	printf("Test 6, memchr, res: %c\n", *(char *)memchr(src, c, 11));
	printf("Test 6.1, memchr: src: %s, char: A\n", src);
	if (memchr(src, 'A', 11) == NULL)
	{
		printf("Test 6.1, memchr, res: NULL\n");
	}
	else
	{
		printf("Test 6.1, memchr, res: Unsuccesful!");
	}

	printf("\nTest 6, ft_memchr: src: %s, char: %c\n", src, c);
	printf("Test 6, ft_memchr, res: %c\n", *(char *)ft_memchr(src, c, 11));
	printf("Test 6.1, ft_memchr: src: %s, char: A\n", src);
	if (ft_memchr(src, 'A', 11) == NULL)
	{
		printf("Test 6.1, ft_memchr, res: NULL\n");
	}
	else
	{
		printf("Test 6.1, ft_memchr, res: Unsuccesful!");
	}
}
