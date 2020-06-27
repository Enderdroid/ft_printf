#include "srcs/libftprintf.h"

int	ft_print_c(t_sarg *pref, char c)//FRIED
{
	char *arg;
	char *pattern;

	if (!(arg = ft_calloc(2, sizeof(char))))
		return(-1);
	*arg = c;
	if (!(pattern = ft_pattern(pref, 1, 1, 0)))
		return (ft_free_p(arg, NULL, NULL, -1));
	ft_printstr(pattern, arg, 1);
	return (ft_free_p(arg, pattern, NULL, 2));
}