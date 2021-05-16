#include "ft_printf_test.h"
//#include <stdio.h>
int	main(void)
{
	//int	n;

	/*test01_parser();
	ft_printf("\n");
	test02_prc_conversion();
	ft_printf("\n");*/
	test03_c_conversion();
	test04_wp_handler();
	test05_s_handler();
	test06_di_handler();

	/*n = ft_printf("\nHello %s %d%%%c", "World", 100, '!');
	ft_printf("\nFT_PRINTF RES: %i\n\n", n);

	ft_printf("POINTER: %i\n", &n);
	printf("POINTER: %p\n", &n);*/
	return 0;
}
