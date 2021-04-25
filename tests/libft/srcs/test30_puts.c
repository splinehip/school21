#include "../includes/test.h"

void	test30_puts(void)
{
	char	c = 'A';
	char	s[] = "Hello World!";
	int		n = 2147483647;
	int		n2 = -2147483648;

	printf("\nTest 30, ft_putchar_fd\n");
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
	printf("Test 30, ft_putstr_fd\n");
	ft_putstr_fd(s, 1);
	ft_putchar_fd('\n', 1);
	printf("Test 30, ft_putendl_fd\n");
	ft_putendl_fd(s, 1);
	printf("Test 30, ft_putnbr_fd\n");
	ft_putnbr_fd(n, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(n2, 1);
	ft_putchar_fd('\n', 1);
}
