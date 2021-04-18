#include "../includes/test.h"

void	test1_memset(void)
{
	char	s[] = "hello world";
	char	s2[] = "hello world";

	printf("\nTest 1, memset, %s", s);
	printf("\nTest 1, res: %s\n", (char *)memset(&s, 'A', 8));
	printf("\nTest 1, ft_memset, %s", s2);
	printf("\nTest 1, res: %s\n", (char *)ft_memset(&s2, 'A', 8));
}
