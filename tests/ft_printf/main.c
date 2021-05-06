#include "ft_printf_test.h"

int	main(void)
{
	printf("%3$.5s %2$'+*1$.3d\n", 10, 1000000, "Hello!");
	test01_parser();
	ft_printf("\n");
	test02_prc_conversion();
	return 0;
}
