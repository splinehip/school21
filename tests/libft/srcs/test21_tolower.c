#include "../includes/test.h"

void	test21_tolower(void)
{
	char	str[] = "Hf0ÿ";
	char	*s;

	s = &str[0];
	while (*s != '\0')
	{
		printf("\nTest 18, tolower, char: %c\n", *s);
		printf("Test 18, tolower, res: %c\n", tolower(*s));

		printf("\nTest 18, ft_tolower, char: %c\n", *s);
		printf("Test 18, ft_tolower, res: %c\n", ft_tolower(*s));

		s++;
	}

}
