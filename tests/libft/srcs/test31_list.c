#include "../includes/test.h"

void	del(void *s)
{
	if (s)
		free(s);
}

void	lstiter(void *s)
{
	char *tmp;

	tmp = s;
	while (*tmp)
	{
		*tmp = ft_toupper(*tmp);
		tmp++;
	}

}

void	*lstmap(void *s)
{
	char *tmp;
	char *res;

	res = ft_memcpy((char *)ft_calloc(ft_strlen(s) + 1, sizeof(char)), s,
					ft_strlen(s));
	tmp = res;
	while (*tmp)
	{
		*tmp = ft_tolower(*tmp);
		tmp++;
	}
	return (res);
}

void	test31_list(void)
{
	t_list	*list;
	t_list	*list2;
	t_list	*tmp_list;
	int		i;
	char	s1[] = "Hello World!";
	char	s2[] = "Mister Pushkin";
	char	s3[] = "Mister Tolstoy";
	char	*str1;
	char	*str2;
	char	*str3;

	str1 = ft_memcpy((char *)ft_calloc(ft_strlen(s1) +1, sizeof(char)), s1,
						ft_strlen(s1));
	str2 = ft_memcpy((char *)ft_calloc(ft_strlen(s2) + 1, sizeof(char)), s2,
						ft_strlen(s2));
	str3 = ft_memcpy((char *)ft_calloc(ft_strlen(s3) + 1, sizeof(char)), s3,
						ft_strlen(s3));

	printf("\nTest 31, listnew\n");
	list = ft_lstnew(str1);
	printf("Test 31, listnew->content: %s\n", (char *)list->content);

	printf("Test 31, lstadd_front\n");
	ft_lstadd_front(&list, ft_lstnew(str2));
	i = 0;
	tmp_list = list;
	while (tmp_list)
	{
		printf("Test 31, list item %d, item->content: %s\n",
				i++, (char *)tmp_list->content);
		tmp_list = tmp_list->next;
	}

	printf("Test 32, lstsize: %d\n", ft_lstsize(list));

	printf("Test 31, lstlast, last list element->content: %s\n",
			(char *)ft_lstlast(list)->content);

	printf("Test 31, lstadd_back\n");
	ft_lstadd_back(&list, ft_lstnew(str3));
	i = 0;
	tmp_list = list;
	while (tmp_list)
	{
		printf("Test 31, list item %d, item->content: %s\n",
				i++, (char *)tmp_list->content);
		tmp_list = tmp_list->next;
	}
	printf("Test 32, lstsize: %d\n\n", ft_lstsize(list));

	printf("Test 31, lstiter\n");
	ft_lstiter(list, lstiter);
	i = 0;
	tmp_list = list;
	while (tmp_list)
	{
		printf("Test 31, list item %d, item->content: %s\n",
				i++, (char *)tmp_list->content);
		tmp_list = tmp_list->next;
	}

	printf("Test 31, lstmap\n");
	list2 = ft_lstmap(list, lstmap, del);
	printf("Test 32, list2 size %d\n", ft_lstsize(list2));
	i = 0;
	tmp_list = list2;
	while (tmp_list)
	{
		printf("Test 31, list item %d, item->content: %s\n",
				i++, (char *)tmp_list->content);
		tmp_list = tmp_list->next;
	}

	printf("Test 31, lstdelone\n");
	ft_lstdelone(ft_lstlast(list), del);
	tmp_list = list;
	while (ft_strncmp(tmp_list->content, "HELLO WORLD!",
			ft_strlen("HELLO WORLD!")))
	{
		tmp_list = tmp_list->next;
	}
	tmp_list->next = NULL;
	printf("Test 32, lstsize: %d\n", ft_lstsize(list));
	i = 0;
	tmp_list = list;
	while (tmp_list)
	{
		printf("Test 31, list item %d, item->content: %s\n",
				i++, (char *)tmp_list->content);
		tmp_list = tmp_list->next;
	}

	printf("Test 31, lstclear\n");
	ft_lstclear(&list, del);
	printf("Test 31, list size: %d\n", ft_lstsize(list));

	printf("Test 31, lstclear\n");
	ft_lstclear(&list2, del);
	printf("Test 31, list2 size: %d\n", ft_lstsize(list));
}
