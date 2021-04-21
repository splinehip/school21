#include "../includes/test.h"

void	test24_substr(void)
{
	char	str[] = "Hello World!";
	char	*subs;

	printf("\nTest 24, ft_substr, str: %s, start: 5\n", str);
	subs = ft_substr(str, 5, 7);
	printf("Test 24, ft_substr, res: %s\n", subs);
	free(subs);
}
