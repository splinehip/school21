#include "../includes/test.h"

void test1(void)
{
    char s[10] = "000000000";

    printf("\nTest 1, ft_memset, %s", s);
    printf("\nTest 1, res: %s\n", (char *)ft_memset(&s, 'A', 8));
}
