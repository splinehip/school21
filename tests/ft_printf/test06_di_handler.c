#include "ft_printf_test.h"

void	test06_di_handler(void)
{
	printf("\n=================== Test 06 di handler 01 ===================\n");
	printf("Format str is: %s\n", "Hello %d, 10");
	ft_printf("Hello %d\n", 10);
	printf("Hello %d\n", 10);

	printf("\n=================== Test 06 di handler 02 ===================\n");
	printf("Format str is: %s\n", "Hello %i, 1414");
	ft_printf("Hello %i\n", 1414);
	printf("Hello %i\n", 1414);

	printf("\n=================== Test 06 di handler 03 ===================\n");
	printf("Format str is: %s\n", "Hello %10d, 10");
	ft_printf("Hello %10d\n", 10);
	printf("Hello %10d\n", 10);

	printf("\n=================== Test 06 di handler 04 ===================\n");
	printf("Format str is: %s\n", "Hello %+10d, 10");
	ft_printf("Hello %+10d\n", 10);
	printf("Hello %+10d\n", 10);

	printf("\n=================== Test 06 di handler 05 ===================\n");
	printf("Format str is: %s\n", "Hello %+05d, 100000");
	ft_printf("Hello %+05d\n", 100000);
	printf("Hello %+05d\n", 100000);

	printf("\n=================== Test 06 di handler 06 ===================\n");
	printf("Format str is: %s\n", "Hello %+05d, 100");
	ft_printf("Hello %+05d\n", 100);
	printf("Hello %+05d\n", 100);

	printf("\n=================== Test 06 di handler 07 ===================\n");
	printf("Format str is: %s\n", "Hello %+03d, 100");
	ft_printf("Hello %+03d\n", 100);
	printf("Hello %+03d\n", 100);

	printf("\n=================== Test 06 di handler 08 ===================\n");
	printf("Format str is: %s\n", "Hello %10i, -1414");
	ft_printf("Hello %10i\n", -1414);
	printf("Hello %10i\n", -1414);

	printf("\n=================== Test 06 di handler 09 ===================\n");
	printf("Format str is: %s\n", "Hello %010i, -1414");
	ft_printf("Hello %010i\n", -1414);
	printf("Hello %010i\n", -1414);

	printf("\n=================== Test 06 di handler 10 ===================\n");
	printf("Format str is: %s\n", "Hello %010.5i, 114");
	ft_printf("Hello %010.5i\n", 114);
	printf("Hello %010.5i\n", 114);

	printf("\n=================== Test 06 di handler 11 ===================\n");
	printf("Format str is: %s\n", "Hello %010.5i, -114");
	ft_printf("Hello %010.5i\n", -114);
	printf("Hello %010.5i\n", -114);

	printf("\n=================== Test 06 di handler 12 ===================\n");
	printf("Format str is: %s\n", "Hello %+010.6i, 114");
	ft_printf("Hello %+010.6i\n", 114);
	printf("Hello %+010.6i\n", 114);
}
