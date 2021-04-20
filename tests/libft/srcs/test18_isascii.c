#include "../includes/test.h"

void	test18_isascii(void)
{
	char	str[] = "H*0ÿ☺";
	char	*s;

	s = &str[0];
	while (*s != '\0')
	{
		printf("\nTest 18, isascii, str: %s, char: %c\n", str, *s);
		printf("Test 18, isascii, res: %d\n", isascii(*s));

		printf("\nTest 18, ft_isascii, str: %s, char: %c\n", str, *s);
		printf("Test 18, ft_isascii, res: %d\n", ft_isascii(*s));

		s++;
	}

}
