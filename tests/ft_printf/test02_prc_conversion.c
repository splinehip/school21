#include "ft_printf_test.h"

void	test02_prc_conversion(void)
{
	char	s[] = "Hello World 100%!\n";

	ft_printf("\n=================== Test 02 %%%% convers ===================\n");
	printf("%s", s);
	ft_printf(s);
}
