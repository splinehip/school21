#include "ft_printf_test.h"

void	test06_di_handler(void)
{
	int n1;
	int n2;

	printf("\n=================== Test 06 di handler 01 ===================\n");
	printf("Format str is: %s\n", "Hello %d, -2147483648");
	n1 = ft_printf("Hello %d\n", -2147483648);
	printf("\n");
	n2 = printf("Hello %ld\n", -2147483648);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test 06 di handler 02 ===================\n");
	printf("Format str is: %s\n", "Hello %i, 1414");
	n1 = ft_printf("Hello %i\n", 1414);
	printf("\n");
	n2 = printf("Hello %i\n", 1414);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test 06 di handler 03 ===================\n");
	printf("Format str is: %s\n", "Hello %10d, 10");
	n1 = ft_printf("Hello %10d\n", 10);
	printf("\n");
	n2 = printf("Hello %10d\n", 10);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test 06 di handler 04 ===================\n");
	printf("Format str is: %s\n", "Hello %+10d, 10");
	n1 = ft_printf("Hello %+10d\n", 10);
	printf("\n");
	n2 = printf("Hello %+10d\n", 10);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test 06 di handler 05 ===================\n");
	printf("Format str is: %s\n", "Hello %+05d, 100000");
	n1 = ft_printf("Hello %+05d\n", 100000);
	printf("\n");
	n2 = printf("Hello %+05d\n", 100000);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test 06 di handler 06 ===================\n");
	printf("Format str is: %s\n", "Hello %+05d, 100");
	n1 = ft_printf("Hello %+05d\n", 100);
	printf("\n");
	n2 = printf("Hello %+05d\n", 100);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test 06 di handler 07 ===================\n");
	printf("Format str is: %s\n", "Hello %+03d, 100");
	n1 = ft_printf("Hello %+03d\n", 100);
	printf("\n");
	n2 = printf("Hello %+03d\n", 100);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test 06 di handler 08 ===================\n");
	printf("Format str is: %s\n", "Hello %10i, -1414");
	n1 = ft_printf("Hello %10i\n", -1414);
	printf("\n");
	n2 = printf("Hello %10i\n", -1414);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test 06 di handler 09 ===================\n");
	printf("Format str is: %s\n", "Hello %010i, -1414");
	n1 = ft_printf("Hello %010i\n", -1414);
	printf("\n");
	n2 = printf("Hello %010i\n", -1414);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test 06 di handler 10 ===================\n");
	printf("Format str is: %s\n", "Hello %010.5i, 114");
	n1 = ft_printf("Hello %010.5i\n", 114);
	printf("\n");
	n2 = printf("Hello %010.5i\n", 114);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test 06 di handler 11 ===================\n");
	printf("Format str is: %s\n", "Hello %010.5i, -114");
	n1 = ft_printf("Hello %010.5i\n", -114);
	printf("\n");
	n2 = printf("Hello %010.5i\n", -114);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test 06 di handler 12 ===================\n");
	printf("Format str is: %s\n", "Hello %+010.6i, 114");
	n1 = ft_printf("Hello %+010.6i\n", 114);
	printf("\n");
	n2 = printf("Hello %+010.6i\n", 114);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test 06 di handler 13 ===================\n");
	printf("Format str is: %s\n", "Hello %010.3i, -14");
	n1 = ft_printf("Hello %010.3i\n", -14);
	printf("\n");
	n2 = printf("Hello %010.3i\n", -14);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test 06 di handler 14 ===================\n");
	printf("Format str is: %s\n", " %.d , 0");
	n1 = ft_printf(" %.d ", 0);
	printf("\n");
	n2 = printf(" %.d ", 0);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test 06 di handler 15 ===================\n");
	printf("Format str is: %s\n", " %-.2d , 0");
	n1 = ft_printf(" %-.2d ", 0);
	printf("\n");
	n2 = printf(" %-.2d ", 0);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test 06 di handler 16 ===================\n");
	printf("Format str is: %s\n", " %-2.2d , 0");
	n1 = ft_printf(" %-2.2d ", 0);
	printf("\n");
	n2 = printf(" %-2.2d ", 0);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test 06 di handler 17 ===================\n");
	printf("Format str is: %s\n", " %-3.2d %10.42d , 0, 0");
	n1 = ft_printf(" %-3.2d %10.42d ", 0, 0);
	printf("\n");
	n2 = printf(" %-3.2d %10.42d ", 0, 0);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test 06 di handler 18 ===================\n");
	printf("Format str is: %s\n", " *%-*.*d* *%*.*d* , 4, 5, 10, 10, 21, -10");
	n1 = ft_printf(" *%-*.*d* *%*.*d* ", 4, 5, 10, 10, 21, -10);
	printf("\n");
	n2 = printf(" *%-*.*d* *%*.*d* ", 4, 5, 10, 10, 21, -10);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test 06 di handler 19 ===================\n");
	printf("Format str is: %s\n", " *%-*.*d* *%*.*d* , 6, 2, 102, 10, 21, -101");
	n1 = ft_printf(" *%-*.*d* *%*.*d* ", 6, 2, 102, 10, 21, -101);
	printf("\n");
	n2 = printf(" *%-*.*d* *%*.*d* ", 6, 2, 102, 10, 21, -101);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test 06 di handler 20 ===================\n");
	printf("Format str is: %s\n", " 0*%0-*d*0 0*%0*d*0 , 21, 1021, 21, -1011");
	n1 = ft_printf(" 0*%0-*d*0 0*%0*d*0 ", 21, 1021, 21, -1011);
	printf("\n");
	n2 = printf(" 0*%-*d*0 0*%0*d*0 ", 21, 1021, 21, -1011);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test 06 di handler 21 ===================\n");
	printf("Format str is: %s\n", " 0*%-0*.10d*0 0*%-0*.0d*0 , 21, 1021, 21, -1011");
	n1 = ft_printf(" 0*%-0*.10d*0 0*%-0*.0d*0 ", 21, 1021, 21, -1011);
	printf("\n");
	n2 = printf(" 0*%-*.10d*0 0*%-*.0d*0 ", 21, 1021, 21, -1011);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test 06 di handler 22 ===================\n");
	printf("Format str is: %s\n", "%0*d, -7, -54");
	n1 = ft_printf("%0*d", -7, -54);
	printf("\n");
	n2 = printf("%0*d", -7, -54);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test 06 di handler 23 ===================\n");
	printf("Format str is: %s\n", " %+-03d , 0");
	n1 = ft_printf("%-03d", 0);
	printf("\n");
	n2 = printf("%-3d", 0);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");
}
