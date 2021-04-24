#include "../includes/test.h"

void	test29_strmapi(void)
{
	char	str[] = "Hello World!";
	char	*res;

	char	f(unsigned int i, char c)
	{
		(void)i;
		c = ft_toupper(c);
		return (c);
	}
	printf("\nTest 29, strmapi, str: %s\n", str);
	res = ft_strmapi(str, &f);
	if (res == NULL)
		printf("Test 29, strmapi res is NULL\n");
	else
		printf("Test 29, strmapi, res: %s | res len: %ld\n",
				res, ft_strlen(res));
}
