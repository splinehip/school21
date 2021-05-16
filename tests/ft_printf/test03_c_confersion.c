#include "ft_printf_test.h"

void	test03_c_conversion(void)
{
	int n1;
	int	n2;

	printf("\n=================== Test 03 c convers 01 ===================\n");
	printf("S is: %s C is: %c\n", "Hello World%c", '!');
	ft_printf("Hello World%c\n", '!');

	printf("\n=================== Test 03 c convers 02 ===================\n");
	printf("S is: %s C is: %c, %c, %c\n", "%cello %corld%c", 'H', 'W', '!');
	ft_printf("%cello %corld%c\n", 'H', 'W', '!');

	printf("\n=================== Test 03 c convers 03 ===================\n");
	printf("S: %s\n", "%-10c, \'0\'");
	printf("\nRES LEN: %d, %d\n", ft_printf("%-10c", '0'), printf("%-10c", '0'));
	ft_printf("\n");

	printf("\n=================== Test 03 c convers 04 ===================\n");
	printf("S: %s\n", "%*c, -2, \'0\'");
	printf("\nRES LEN: %d, %d\n", ft_printf("%*c", -2, '0'),
			printf("%*c", -2, '0'));
	ft_printf("\n");

	printf("\n=================== Test 03 c convers 05 ===================\n");
	printf("S: %s\n", "%-c%-c*, 1, 0");
	printf("\nRES LEN: %d, %d\n", ft_printf("%-c%-c*", 1, 0),
			printf("%-c%-c*", 1, 0));
	ft_printf("\n");

	printf("\n=================== Test 03 c convers 06 ===================\n");
	printf("S: %s\n", " %c , \'0\'");
	printf("\nRES LEN: %d, %d\n", ft_printf(" %c ", '0'),
			printf(" %c ", '0'));
	ft_printf("\n");

	printf("\n=================== Test 03 c convers 07 ===================\n");
	printf("S: %s\n", "%-c%-c%c*, 1, \'0\', 0");
	n1 = ft_printf("%-c%-c%c*", 1, '0', 0);
	printf("\n");
	n2 = printf("%-c%-c%c*", 1, '0', 0);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test 03 c convers 08 ===================\n");
	printf("S: %s\n", " -%*c* -%-*c* , -2, 0, 2, 0");
	n1 = ft_printf(" -%*c* -%-*c* ", -2, 0, 2, 0);
	printf("\n");
	n2 = printf(" -%*c* -%-*c* ", -2, 0, 2, 0);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test 03 c convers 09 ===================\n");
	printf("S: %s\n", "-%-2c*, 0");
	n1 = ft_printf("-%-2c*", 0);
	printf("\n");
	n2 = printf("-%-2c*", 0);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");

	printf("\n=================== Test 03 c convers 10 ===================\n");
	printf("S: %s\n", "%*c, 0, \'0\'");
	n1 = ft_printf("%*c", 0, '0');
	printf("\n");
	n2 = printf("%*c", 0, '0');
	printf("\nRES LEN: %d, %d\n", n1, n2);
	ft_printf("\n");
}
