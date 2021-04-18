#include "../includes/test.h"

void	test2_bzero(void)
{
	char	s[] = "hello world";
	char	s2[] = "hello world";

	printf("\nTest 2 bzero: %s\n", s);
	bzero(&s, 5);
	printf("Test 2 res: %s\n", s);
	printf("\nTest 2 ft_bzero: %s\n", s2);
	ft_bzero(&s2, 5);
	printf("Test 2 res: %s\n", s2);
}
