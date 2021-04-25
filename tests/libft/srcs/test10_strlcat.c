#include "../includes/test.h"

void	test10_strlcat(void)
{
	char	dest1[12] = "hello ";
	char	dest2[12] = "hello ";
	char	src[] = "world";

	char *str = "the cake is a lie !\0I'm hidden lol\r\n";
	char buff1[0xF00] = "there is no stars in the sky";
	char buff2[0xF00] = "there is no stars in the sky";
	size_t max = strlen("the cake is a lie !\0I'm hidden lol\r\n") + strlen("there is no stars in the sky");

	printf("\nTest 10, strlcat, buff1: %s, src: %s\n", buff1, str);
	strlcat(buff1, str, max);
	printf("Test 10, strlcat, res: buff1: %s, returns: %ld\n",
		buff1, ft_strlen(buff1));

	printf("\nTest 10, ft_strlcat, buff2: %s, src: %s\n", buff2, str);
	ft_strlcat(buff2, str, max);
	printf("Test 10, ft_strlcat, res: buff2: %s, returns: %ld\n",
		buff2, ft_strlen(buff2));


	printf("\nTest 10, strlcat, dest: %s, src: %s\n", dest1, src);
	printf("Test 10, strlcat, res: dest: %s, returns: %ld\n",
		dest1, strlcat(dest1, src, sizeof(dest1)));

	printf("\nTest 10, ft_strlcat, dest: %s, src: %s\n", dest2, src);
	printf("Test 10, ft_strlcat, res: dest: %s, returns: %ld\n",
		dest2, ft_strlcat(dest2, src, sizeof(dest2)));


}
