#include "ft_printf_test.h"

void	test05_s_handler(void)
{
	printf("\n=================== Test 05 s handler 01 ===================\n");
	printf("Fromat str is: %s\n", "Hello %*s, 10, \"World!\"");
	ft_printf("Hello %*s\n", 10, "World!");
	printf("Hello %*s\n", 10, "World!");

	printf("\n=================== Test 05 s handler 02 ===================\n");
	printf("Fromat str is: %s\n", "Hello %-10s, \"World!\"");
	ft_printf("Hello %-10s\n", "World!");
	printf("Hello %-10s\n", "World!");
}
