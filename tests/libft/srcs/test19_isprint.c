#include "../includes/test.h"

void	test19_isprint(void)
{
	char	str[] = " H";
	char	*s;

	s = &str[0];
	while (*s != '\0')
	{
		printf("\nTest 18, isprint, char: %c\n", *s);
		printf("Test 18, isprint, res: %d\n", isprint(*s));

		printf("\nTest 18, ft_isprint, char: %c\n", *s);
		printf("Test 18, ft_isprint, res: %d\n", ft_isprint(*s));

		s++;
	}
	printf("\nTest 18, isprint, char: %c\n", 127);
	printf("Test 18, isprint, res: %d\n", isprint(127));

	printf("\nTest 18, ft_isprint, char: %c\n", 127);
	printf("Test 18, ft_isprint, res: %d\n", ft_isprint(127));

}
