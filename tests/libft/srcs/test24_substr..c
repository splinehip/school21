#include "../includes/test.h"

void	test24_substr(void)
{
	char	str[] = "lorem ipsum dolor sit amet";
	char	*subs;

	printf("\nTest 24, ft_substr, str: %s, start: 7, n: 0\n", str);
	subs = ft_substr(str, 7, 100000000000);
	printf("Test 24, ft_substr, res: %s\n", subs);
	free(subs);

	printf("\nTest 24, ft_substr, str: %s, start: 0, n: 0\n", str);
	subs = ft_substr(str, 0, 0);
	printf("Test 24, ft_substr, res: %s\n", subs);
	free(subs);
}
