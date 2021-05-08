#include "ft_printf_test.h"

void	test03_c_conversion(void)
{
	char c = '!';
	char c1 = 'H';
	char c2 = 'W';

	printf("\n=================== Test 03 c convers 01 ===================\n");
	printf("S is: %s C is: %c\n", "Hello World%c", c);
	ft_printf("Hello World%c\n", c);

	printf("\n=================== Test 03 c convers 02 ===================\n");
	printf("S is: %s C is: %c, %c, %c\n", "%cello %corld%c", c1, c2, c);
	ft_printf("%cello %corld%c\n", c1, c2, c);
}
