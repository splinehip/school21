#include "../includes/test.h"

void	test23_strdup(void)
{
	char	s[] = "Hello World!";
	char 	*s_dup;

	s_dup = strdup(s);
	if (s_dup != NULL)
	{
		printf("\nTest 23, strdup, new str: %s\n", s_dup);
	}
	else
	{
		printf("\nTest 23, strdup, new str is NULL\n");
	}
	free(s_dup);

	s_dup = ft_strdup(s);
	if (s_dup != NULL)
	{
		printf("Test 23, ft_strdup, new str: %s\n", s_dup);
	}
	else
	{
		printf("Test 23, ft_strdup, new str is NULL\n");
	}
	free(s_dup);
}
