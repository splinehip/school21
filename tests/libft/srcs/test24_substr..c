#include "../includes/test.h"

void	test24_substr(void)
{
	char	str[] = "0123456789";
	char	*subs;

	printf("\nTest 24, ft_substr, str: %s, start: 9, n: 10\n", str);
	subs = ft_substr(str, 9, 10);
	printf("Test 24, ft_substr, res: %s, res len: %ld\n", subs, ft_strlen(subs));
	free(subs);

	printf("\nTest 24, ft_substr, str: %s, start: 0, n: 0\n", str);
	subs = ft_substr(str, 0, 0);
	printf("Test 24, ft_substr, res: %s\n", subs);
	free(subs);
}
