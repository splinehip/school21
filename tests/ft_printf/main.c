#include "ft_printf_test.h"
//#include <stdio.h>
int	main(void)
{
	test01_parser();
	test02_prc_conversion();
	test03_c_conversion();
	test04_wp_handler();
	test05_s_handler();
	test06_di_handler();
	test07_p_handler();
	test08_u_handler();
	test09_xX_handler();

	int n1;
	int n2;
	printf("\n=================== Test %% 01 ======================\n");
	printf("Format str is: %s\n", "%5% %-0.5%");
	n1 = ft_printf("%5% %-0.5%");
	printf("\n");
	n2 = printf("%5% %-0.5%");
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test %% 02 ======================\n");
	printf("Format str is: %s\n","%*.*%! %+# -10.5%, -10, 10");
	n1 = ft_printf("%*.*%! !%+# -10.5%!", -10, 10);
	printf("\n");
	n2 = printf("%*.*%! !%+# -10.5%!", -10, 10);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test MIX 01 ======================\n");
	printf("Format str is: %s\n", "\"\"");
	n1 = ft_printf("");
	printf("\n");
	n2 = printf("");
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test MIX 02 ======================\n");
	printf("Format str is: %s\n", " %s %.5s, \"\", NULL");
	n1 = ft_printf(" %s %10.6s", "23", NULL);
	printf("\n");
	n2 = printf(" %s %10.6s", "23", NULL);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test ' ' 01 ======================\n");
	printf("Format str is: %s\n", " % 03d , -1");
	n1 = ft_printf("% 03d!", -1);
	printf("\n");
	n2 = printf("% 03d!", -1);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test ' ' 02 ======================\n");
	printf("Format str is: %s\n", "% -03d, 0");
	n1 = ft_printf("% -03d", 0);
	printf("\n");
	n2 = printf("% -03d", 0);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test ' ' 03 ======================\n");
	printf("Format str is: %s\n", "% d, -1");
	n1 = ft_printf("% d", -1);
	printf("\n");
	n2 = printf("% d", -1);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test ' ' 03 ======================\n");
	printf("Format str is: %s\n", "% 2d, -1");
	n1 = ft_printf("% 5d", -1);
	printf("\n");
	n2 = printf("% 5d", -1);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	return 0;
}
