#include "ft_printf_test.h"

void	test05_s_handler(void)
{
	int n1;
	int	n2;

	printf("\n=================== Test 05 s handler 01 ===================\n");
	printf("Format str is: %s\n", "Hello %*s, 10, \"World!\"");
	n1 = ft_printf("Hello %*s", 10, "World!");
	printf("\n");
	n2 = printf("Hello %*s", 10, "World!");
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test 05 s handler 02 ===================\n");
	printf("Format str is: %s\n", "Hello %-10s, \"World!\"");
	n1 = ft_printf("Hello %-10s\n", "World!");
	printf("\n");
	n2 = printf("Hello %-10s\n", "World!");
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test 05 s handler 03 ===================\n");
	printf("Format str is: %s\n", "Hello %-10.3s, \"World!\"");
	n1 = ft_printf("Hello %-10.3s\n", "World!");
	printf("\n");
	n2 = printf("Hello %-10.3s\n", "World!");
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test 05 s handler 04 ===================\n");
	printf("Format str is: %s\n", "Hello %10.3s, \"World!\"");
	n1 = ft_printf("Hello %10.3s\n", "World!");
	printf("\n");
	n2 = printf("Hello %10.3s\n", "World!");
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test 05 s handler 05 ===================\n");
	printf("Format str is: %s\n", "Hello %-10.s, \"World!\"");
	n1 = ft_printf("Hello %-10.s\n", "World!");
	printf("\n");
	n2 = printf("Hello %-10.s\n", "World!");
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test 05 s handler 06 ===================\n");
	printf("Format str is: %s\n", "%s, \"\"");
	n1 = ft_printf("%s", "");
	printf("\n");
	n2 = printf("%s", "");
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test 05 s handler 07 ===================\n");
	printf("Format str is: %s\n", " %1s %1s , \"123\", \"4567\"");
	n1 = ft_printf(" %1s %1s ", "123", "4567");
	printf("\n");
	n2 = printf(" %1s %1s ", "123", "4567");
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test 05 s handler 08 ===================\n");
	printf("Format str is: %s\n", " %-4s %4s , \"123\", \"4567\"");
	n1 = ft_printf(" %-4s %4s ", "123", "4567");
	printf("\n");
	n2 = printf(" %-4s %4s ", "123", "4567");
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");
}
