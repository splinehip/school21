#include "ft_printf_test.h"

void	test01_parser(void)
{
	size_t	i;
	char	*s[18];

	s[0] = "%%";
	s[1] = "%%%%";
	s[2] = "%-0+.3d";
	s[3] = "%-0+.3d%-0+.4u";
	s[4] = "AAA%%";
	s[5] = "AAA%%WWW";
	s[6] = "AAA%%%%";
	s[7] = "AAA%%%%WWW";
	s[8] = "AAA%%%-0d";
	s[9] = "AAA%%WWW";
	s[10] = "AAA%%%%WWW%d";
	s[11] = "AAA%%%%WWW%-0.5d%%%dDDD";
	s[12] = "\\AAA%%WWW%-0.3dDDD";
	s[13] = "AAA%%WWW%-0.3dDDD\\";
	s[14] = "\\AAA%%WWW%-0.3dDDD\\";
	s[15] = "AAA%d%u%c%%WWW%d%x";
	s[16] = "\nAAA%d%u%c%%WWW%d%x\n";
	s[17] = NULL;
	i = 0;
	while (s[i] != NULL)
	{
		printf("\n=================== Test 01 parser: %ld ===================\n",
				i);
		printf("S%ld: %s\n", i, s[i]);
		ft_printf(s[i++]);
	}
}
