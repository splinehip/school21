#ifndef TEST_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <bsd/string.h>
# include "../../../libft/libft.h"
# define TEST_H

void	test1_memset(void);
void	test2_bzero(void);
void	test3_memcpy(void);
void	test4_memccpy(void);
void	test5_memmove(void);
void	test6_memchr(void);
void	test7_memcpm(void);
void	test8_strlen(void);
void	test9_strlcpy(void);
void	test10_strlcat(void);
void	test11_strchr(void);
void	test12_strrchr(void);
void	test13_strnstr(void);
void	test14_strncmp(void);
void	test15_atoi(void);
void	test16_isalpha(void);
void	test17_isalnum(void);
void	test18_isascii(void);
void	test19_isprint(void);
void	test20_toupper(void);
void	test21_tolower(void);
void	test22_calloc(void);
void	test23_strdup(void);
void	test24_substr(void);
void	test25_strjoin(void);
void	test26_strtrim(void);
int	test27_split(void);
#endif
