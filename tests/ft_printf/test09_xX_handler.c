#include "ft_printf_test.h"

void	test09_xX_handler(void)
{
	int n1;
	int n2;

	printf("\n=================== Test 09 xX handler 01 ===================\n");
	printf("Format str is: %s\n", "%x %X, 12345, 12345");
	n1 = ft_printf("%x %X", 12345, 12345);
	printf("\n");
	n2 = printf("%x %X", 12345, 12345);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test 09 xX handler 02 ===================\n");
	printf("Format str is: %s\n", "%#x %#X, 12345, 12345");
	n1 = ft_printf("%#x %#X", 12345, 12345);
	printf("\n");
	n2 = printf("%#x %#X", 12345, 12345);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test 09 xX handler 03 ===================\n");
	printf("Format str is: %s\n", " %x , 0");
	n1 = ft_printf(" %x ", 0);
	printf("\n");
	n2 = printf(" %x ", 0);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test 09 xX handler 04 ===================\n");
	printf("Format str is: %s\n", "%.0x, 5");
	n1 = ft_printf("%0.0x", 5);
	printf("\n");
	n2 = printf("%.0x", 5);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test 09 xX handler 04 ===================\n");
	printf("Format str is: %s\n", "%#.10x, 5");
	n1 = ft_printf("%#.10x", 5);
	printf("\n");
	n2 = printf("%#.10x", 5);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");
}
