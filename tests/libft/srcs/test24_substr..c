#include "../includes/test.h"

void	test24_substr(void)
{
	char	str[] = "Hello World!";
	char	*subs;

	printf("\nTest 24, ft_substr, str: %s, start: 14\n", str);
	subs = ft_substr(str, 14, 3);
	printf("Test 24, ft_substr, res: %s\n", subs);
	free(subs);

	printf("\nTest 24, ft_substr, str: %s, start: 6\n", str);
	subs = ft_substr(str, 6, 3);
	printf("Test 24, ft_substr, res: %s\n", subs);
	free(subs);
}
