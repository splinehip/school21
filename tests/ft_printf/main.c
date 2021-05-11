#include "ft_printf_test.h"
//#include <stdio.h>
int	main(void)
{
	//printf("%3$.5s %2$'+*1$.3d\n", 10, 1000000, "Hello!");
	/*test01_parser();
	ft_printf("\n");
	test02_prc_conversion();
	ft_printf("\n");*/
	//printf("\nTest ft_strjoinch %s\n", ft_strjoinch("TEST ", '!'));
	test03_c_conversion();
	test04_wp_handler();
	test05_s_handler();
	test06_di_handler();

	ft_printf("\nHello %s %d%%%c\n\n", "World", 100, '!');

	int	n = 10;
	ft_printf("POINTER: %i\n", &n);
	printf("POINTER: %p\n", &n);
	return 0;
}
