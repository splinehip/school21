#include "../includes/test.h"

void	test3_memcpy(void)
{
	char	s1[] = "hello world";
	char	s2[6] = "";
	char	s3[] = "hello world";
	char	s4[6] = "";

	printf("\nTest 3 memcpy: %s\n", s1);
	printf("Test 3 res: %s\n", (char *)memcpy(&s2, &s1, 5));
	printf("\nTest 3 ft_memcpy: %s\n", s3);
	printf("Test 3 res: %s\n", (char *)ft_memcpy(&s4, &s3, 5));
}
