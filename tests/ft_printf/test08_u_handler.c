#include "ft_printf_test.h"

void	test08_u_handler(void)
{
	int n1;
	int n2;

	printf("\n=================== Test 08 u handler 01 ===================\n");
	printf("Format str is: %s\n", " %-3.2u %10.42u , 1, -1");
	n1 = ft_printf(" %-3.2uu %10.42udu ", 1, -1);
	printf("\n");
	n2 = printf(" %-3.2uu %10.42udu ", 1, -1);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");
}
