#include "../includes/test.h"

void	test16_isalpha(void)
{
	char	str[] = "Hi*";
	char	*s;

	s = &str[0];
	while (*s != '\0')
	{
		printf("\nTest 16, isalpha, str: %s, char: %c\n", str, *s);
		printf("Test 16, isalpha, res: %d\n", isalpha(*s));

		printf("\nTest 16, ft_isalpha, str: %s, char: %c\n", str, *s);
		printf("Test 16, ft_isalpha, res: %d\n", ft_isalpha(*s));

		s++;
	}

}
