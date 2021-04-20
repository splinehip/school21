#include "../includes/test.h"

void	test17_isalnum(void)
{
	char	str[] = "H*0☺";
	char	*s;

	s = &str[0];
	while (*s != '\0')
	{
		printf("\nTest 17, isalnum, str: %s, char: %c\n", str, *s);
		printf("Test 17, isalnum, res: %d\n", isalnum(*s));

		printf("\nTest 17, ft_isalnum, str: %s, char: %c\n", str, *s);
		printf("Test 17, ft_isalnum, res: %d\n", ft_isalnum(*s));

		s++;
	}

}
