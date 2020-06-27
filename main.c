#include "libftprintf.h"
#include <stdio.h>

int main(void)
{
	int x = ft_printf("%23d|%-23d|%+23d|% 23d|%023d", 0, 0, 0, 0, 0);
	printf("\n|RET -  %i|\n", x);
	return 0;
}