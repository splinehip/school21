#include "../includes/test.h"

void	test5_memmove(void)
{
	char	src[] = "1234567890";
	char	dest[] = "1234567890";
	char	src1[] = "1234567890";
	char	dest1[] = "1234567890";

	printf("\nTest 5, memmove: src: %s, dest: %s\n", src, dest);
	printf("Test 5, memmove resp: %s\n",
			(char *)memmove(&src[4], &src, 5));
	printf("Test 5, memmove, res: src: %s, dest: %s\n", src, dest);

	printf("\nTest 5, ft_memmove: src: %s, dest: %s\n", src1, dest1);
	printf("Test 5, ft_memmove resp: %s\n",
			(char *)ft_memmove(&src1[4], &src1, 5));
	printf("Test 5, ft_memmove, res: src: %s, dest: %s\n", src1, dest1);
}
