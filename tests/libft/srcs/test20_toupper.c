#include "../includes/test.h"

void	test20_toupper(void)
{
	char	str[] = "Hf0ÿ";
	char	*s;

	s = &str[0];
	while (*s != '\0')
	{
		printf("\nTest 18, toupper, char: %c\n", *s);
		printf("Test 18, toupper, res: %c\n", toupper(*s));

		printf("\nTest 18, ft_toupper, char: %c\n", *s);
		printf("Test 18, ft_toupper, res: %c\n", ft_toupper(*s));

		s++;
	}

}
