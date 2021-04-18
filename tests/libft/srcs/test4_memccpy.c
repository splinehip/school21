#include "../includes/test.h"

void	test4_memccpy(void)
{
	char	src[] = "hello world";
	char	dest[] = "00000000000";

	printf("\nTest 4.1 memccpy: %s\n", src);
	printf("Test 4.1 res: ");
	if (memccpy(dest, src, ' ', 6))
	{
		printf("%s, %s\n", dest, (char *)memccpy(dest, src, ' ', 6));
	}else
	{
		printf("NULL\n");
	}

	printf("\nTest 4.1 ft_memccpy: %s\n", src);
	printf("Test 4.1 res: ");
	if (ft_memccpy(dest, src, ' ', 6))
	{
		printf("%s, %s\n", dest, (char *)ft_memccpy(dest, src, ' ', 6));
	}else
	{
		printf("NULL\n");
	}

	printf("\nTest 4.2 memccpy: %s\n", src);
	printf("Test 4.2 res: ");
	if (memccpy(dest, src, '0', 6))
	{
		printf("%s, %s\n", dest, (char *)memccpy(dest, src, ' ', 6));
	}else
	{
		printf("NULL\n");
	}
	printf("\nTest 4.2 ft_memccpy: %s\n", src);
	printf("Test 4.2 res: ");
	if (ft_memccpy(dest, src, '0', 6))
	{
		printf("%s, %s\n", dest, (char *)ft_memccpy(dest, src, ' ', 6));
	}else
	{
		printf("NULL\n");
	}
}
