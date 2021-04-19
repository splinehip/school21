#include "../includes/test.h"

void	test9_strlcpy(void)
{
	char	src[] = "hello wrold";
	char	dest1[5];
	char	dest2[5];

	printf("\nTest 9, strlcpy, src: %s, dest size: %ld\n", src, sizeof(dest1));
	printf("Test 9, strlcpy, res: dest: %s, returns: %ld\n",
			dest1, strlcpy(dest1, src, sizeof(dest1)));

	printf("\nTest 9, ft_strlcpy, src: %s, dest size: %ld\n", src, sizeof(dest2));
	printf("Test 9, ft_strlcpy, res: dest: %s, returns: %ld\n",
			dest2, ft_strlcpy(dest2, src, sizeof(dest2)));
}
