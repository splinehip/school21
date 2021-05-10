#include "ft_printf_test.h"

void	test04_wp_handler(void)
{
	printf("\n=================== Test 04 wp handler 01 ===================\n");
	printf("Get wp from va\n");
	printf("Fromat str is: %s\n", "Hello World%*.*c, 10, 5, !");
	ft_printf("Hello World%*.*c\n", 10, 5, '!');

	printf("\n=================== Test 04 wp handler 02 ===================\n");
	printf("Get wp from va\n");
	printf("Fromat str is: %s\n", "Hello World%*.c, 10, !");
	ft_printf("Hello World%*.c\n", 10, '!');

	printf("\n=================== Test 04 wp handler 03 ===================\n");
	printf("Get wp from va\n");
	printf("Fromat str is: %s\n", "Hello World%.*c, 5, !");
	ft_printf("Hello World%.*c\n", 5, '!');

	printf("\n=================== Test 04 wp handler 04 ===================\n");
	printf("Get wp from va\n");
	printf("Fromat str is: %s\n", "Hello World%*c, 10, !");
	ft_printf("Hello World%*c\n", 10, '!');

	printf("\n=================== Test 04 wp handler 05 ===================\n");
	printf("Get wp from str\n");
	printf("Fromat str is: %s\n", "Hello World%5.10c, !");
	ft_printf("Hello World%5.10c\n", '!');

	printf("\n=================== Test 04 wp handler 06 ===================\n");
	printf("Get wp from str\n");
	printf("Fromat str is: %s\n", "Hello World%-05.10c, !");
	ft_printf("Hello World%-05.10c\n", '!');

	printf("\n=================== Test 04 wp handler 07 ===================\n");
	printf("Get wp from str\n");
	printf("Fromat str is: %s\n", "Hello World%.10c, !");
	ft_printf("Hello World%.10c\n", '!');

	printf("\n=================== Test 04 wp handler 08 ===================\n");
	printf("Get wp from str\n");
	printf("Fromat str is: %s\n", "Hello World%10.c, !");
	ft_printf("Hello World%10.c\n", '!');

	printf("\n=================== Test 04 wp handler 09 ===================\n");
	printf("Get wp from str\n");
	printf("Fromat str is: %s\n", "Hello World%.c, !");
	ft_printf("Hello World%.c\n", '!');

	printf("\n=================== Test 04 wp handler 10 ===================\n");
	printf("Get wp from va and str\n");
	printf("Fromat str is: %s\n", "Hello World%10.*c, 5, !");
	ft_printf("Hello World%10.*c\n", 5, '!');

	printf("\n=================== Test 04 wp handler 11 ===================\n");
	printf("Get wp from va and str\n");
	printf("Fromat str is: %s\n", "Hello World%+*.5c, 10, !");
	ft_printf("Hello World%+*.5c\n", 10, '!');
}
