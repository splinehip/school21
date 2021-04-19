#include "../includes/test.h"

void	test10_strlcat(void)
{
	char	dest1[12] = "hello ";
	char	dest2[12] = "hello ";
	char	src[] = "world";

	printf("\nTest 10, strlcat, dest: %s, src: %s\n", dest1, src);
	printf("Test 10, strlcat, res: dest: %s, returns: %ld\n",
		dest1, strlcat(dest1, src, sizeof(dest1)));

	printf("\nTest 10, ft_strlcat, dest: %s, src: %s\n", dest2, src);
	printf("Test 10, ft_strlcat, res: dest: %s, returns: %ld\n",
		dest2, ft_strlcat(dest2, src, sizeof(dest2)));
}
