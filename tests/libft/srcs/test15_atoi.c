#include "../includes/test.h"

void	test15_atoi(void)
{
	char str1[] = " ----+--+-1234abr567";
	char str2[] = " -----+--+-1234abr567";
	char str3[] = "\f\n\r\t\v ----+--+-1234abr567";
	char str4[] = "\f\n\r\t\v --\t--+--+-1234abr567";
	char str5[] = " ++++ ++1234abr567";
	char str6[] = " ++++bb++1234abr567";
	char str7[] = "abr";
	char str8[] = "	123";

	printf("\nTest atoi, str is: %s\nint is: %d\n", str1, atoi(str1));
	printf("Test atoi, str is: %s\nint is: %d\n", str2, atoi(str2));
	printf("Test atoi, str is: %s\nint is: %d\n", str3, atoi(str3));
	printf("Test atoi, str is: %s\nint is: %d\n", str4, atoi(str4));
	printf("Test atoi, str is: %s\nint is: %d\n", str5, atoi(str5));
	printf("Test atoi, str is: %s\nint is: %d\n", str6, atoi(str6));
	printf("Test atoi, str is: %s\nint is: %d\n", str7, atoi(str7));
	printf("Test atoi, str is: %s\nint is: %d\n", str8, atoi(str8));

	printf("\nTest ft_atoi, str is: %s\nint is: %d\n", str1, ft_atoi(str1));
	printf("Test ft_atoi, str is: %s\nint is: %d\n", str2, ft_atoi(str2));
	printf("Test ft_atoi, str is: %s\nint is: %d\n", str3, ft_atoi(str3));
	printf("Test ft_atoi, str is: %s\nint is: %d\n", str4, ft_atoi(str4));
	printf("Test ft_atoi, str is: %s\nint is: %d\n", str5, ft_atoi(str5));
	printf("Test ft_atoi, str is: %s\nint is: %d\n", str6, ft_atoi(str6));
	printf("Test ft_atoi, str is: %s\nint is: %d\n", str7, ft_atoi(str7));
	printf("Test ft_atoi, str is: %s\nint is: %d\n", str8, ft_atoi(str8));
}
