#include "../includes/test.h"

void	test25_strjoin(void)
{
	char	str1[] = "Hello ";
	char	str2[] = "World!";
	char	*joined_str;

	printf("\nTest 25, ft_strjoin, str1: %s, str2: %s\n", str1, str2);
	joined_str = ft_strjoin(str1, str2);
	if (joined_str != NULL)
	{
		printf("Test 25, ft_strjoin, res: %s | res len: %ld\n", joined_str,
				ft_strlen(joined_str));
		free(joined_str);
	}
	else
		printf("Test 25, ft_strjoin res is NULL\n");
}
