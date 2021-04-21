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
	char str9[] = "--124";
	char str10[] = "-124";
	char str11[] = "+4294967296";

	printf("\nTest15 atoi, str is: %s\nint is: %d\n", str1, atoi(str1));
	printf("\nTest15 atoi, str is: %s\nint is: %d\n", str2, atoi(str2));
	printf("\nTest15 atoi, str is: %s\nint is: %d\n", str3, atoi(str3));
	printf("\nTest15 atoi, str is: %s\nint is: %d\n", str4, atoi(str4));
	printf("\nTest15 atoi, str is: %s\nint is: %d\n", str5, atoi(str5));
	printf("\nTest15 atoi, str is: %s\nint is: %d\n", str6, atoi(str6));
	printf("\nTest15 atoi, str is: %s\nint is: %d\n", str7, atoi(str7));
	printf("\nTest15 atoi, str is: %s\nint is: %d\n", str8, atoi(str8));
	printf("\nTest15 atoi, str is: %s\nint is: %d\n", str9, atoi(str9));
	printf("\nTest15 atoi, str is: %s\nint is: %d\n", str10, atoi(str10));
	printf("\nTest15 atoi, str is: %s\nint is: %d\n", str11, atoi(str11));

	printf("\nTest15 ft_atoi, str is: %s\nint is: %d\n", str1, ft_atoi(str1));
	printf("\nTest15 ft_atoi, str is: %s\nint is: %d\n", str2, ft_atoi(str2));
	printf("\nTest15 ft_atoi, str is: %s\nint is: %d\n", str3, ft_atoi(str3));
	printf("\nTest15 ft_atoi, str is: %s\nint is: %d\n", str4, ft_atoi(str4));
	printf("\nTest15 ft_atoi, str is: %s\nint is: %d\n", str5, ft_atoi(str5));
	printf("\nTest15 ft_atoi, str is: %s\nint is: %d\n", str6, ft_atoi(str6));
	printf("\nTest15 ft_atoi, str is: %s\nint is: %d\n", str7, ft_atoi(str7));
	printf("\nTest15 ft_atoi, str is: %s\nint is: %d\n", str8, ft_atoi(str8));
	printf("\nTest15 ft_atoi, str is: %s\nint is: %d\n", str9, ft_atoi(str9));
	printf("\nTest15 ft_atoi, str is: %s\nint is: %d\n", str10, ft_atoi(str10));
	printf("\nTest15 ft_atoi, str is: %s\nint is: %d\n", str11, ft_atoi(str11));
}
