#include "../includes/test.h"

void	test26_strtrim(void)
{
	char	str[] = "Hello World";
	char	set[] = "!&}*";
	char	*str_trimed;

	printf("\nTest 26, ft_strtrim, str: %s, set: %s\n", str, set);
	str_trimed = ft_strtrim(str, set);
	printf("Test 26, ft_strtrim, res: %s\n", str_trimed);
	free(str_trimed);
}
