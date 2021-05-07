#include "ft_printf_test.h"

void	test03_c_conversion(void)
{
	char c = '!';

	printf("\n=================== Test 03 c convers ===================\n");
	printf("S is: %s C is: %c\n", "Hello World%c", c);
	ft_printf("Hello World%c\n", c);
}
