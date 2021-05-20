#include "ft_printf_test.h"

void	test07_p_handler(void)
{
	int n1;
	int n2;
	int n3;

	n3 = 0;
	printf("\n=================== Test 07 p handler 01 ===================\n");
	printf("Format str is: %s\n", "%p, &n");
	n1 = ft_printf("%p\n", &n3);
	printf("\n");
	n2 = printf("%p\n", &n3);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test 07 p handler 02 ===================\n");
	printf("Format str is: %s\n", "%100p, &n");
	n1 = ft_printf("%100p\n", &n3);
	printf("\n");
	n2 = printf("%100p\n", &n3);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test 07 p handler 03 ===================\n");
	printf("Format str is: %s\n", "%-100p, &n");
	n1 = ft_printf("%-100p\n", &n3);
	printf("\n");
	n2 = printf("%-100p\n", &n3);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test 07 p handler 04 ===================\n");
	printf("Format str is: %s\n", " %10p %10p , 1, -1");
	n1 = ft_printf(" %10p %10p ", 1, -1);
	printf("\n");
	n2 = printf(" %10p %10p ", 1, -1);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test 07 p handler 05 ===================\n");
	printf("Format str is: %s\n", " %10p %-10p , 0, 0");
	n1 = ft_printf(" %10p %-10p ", 0, 0);
	printf("\n");
	n2 = printf(" %10p %-10p ", 0, 0);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");
}
