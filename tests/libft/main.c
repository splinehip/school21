#include "includes/test.h"

int	main(void)
{
	test1_memset();
	test2_bzero();
	test3_memcpy();
	test4_memccpy();
	test5_memmove();
	test6_memchr();
	test7_memcpm();
	test8_strlen();
	test9_strlcpy();
	test10_strlcat();
	test11_strchr();
	test12_strrchr();
	test13_strnstr();
	test14_strncmp();
	test15_atoi();
	test16_isalpha();
	test17_isalnum();
	test18_isascii();
	test19_isprint();
	test20_toupper();
	test21_tolower();
	test22_calloc();
	test23_strdup();
	test24_substr();
	test25_strjoin();
	test26_strtrim();
	test27_split();
	test28_itoa();
	test29_strmapi();
	test30_puts();
	test31_list();
	test32_uitoa();
	printf("POW RES: %lld, %lld\n", ft_uintpow(2, 0), ft_uintpow(2, 32));
	int n;
	n = 10;
	char *res;
	printf(("\nFT_TOBASE() is: %s, printf p: %p\n"), res = ft_tobase(10, 16, &n), &n);
	free(res);
	return (0);
}
