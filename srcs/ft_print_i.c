#include "srcs/libftprintf.h"

int			ft_print_i(t_sarg *pref, long long int num)//FREED
{
	char	*arg;
	char	*s_num;
	size_t	minus;
	size_t	len;
	char	*pattern;

	arg = NULL;
	minus = 1;
	s_num = ft_itoa(num);
	if (num >= 0 && ft_strchr(pref->flags, ' '))
		arg = ft_strjoin(" ", s_num);
	else if (num >= 0 && ft_strchr(pref->flags, '+'))
		arg = ft_strjoin("+", s_num);
	else if (num >= 0)
		minus = 0;
	if (!arg && !(arg = ft_strdup(s_num)))
		return (-1);
	len = ft_strlen(arg);
	if(!(pattern = ft_pattern(pref, len, len - minus, 1)))
		return (ft_free_p(arg, NULL, s_num, -1));
	ft_printstr(pattern, arg, 0);
	//printf("\n[ARG: |%s|; PATTERN: |%s|]\n", arg, pattern);
	return (ft_free_p(arg, pattern, s_num, 2));
}

/*
if (num >= 0 && ft_strchr(pref->flags, ' '))
		arg = ft_strjoin(" ", ft_itoa(num));
	else if (num >= 0 && ft_strchr(pref->flags, '+'))
		arg = ft_strjoin("+", ft_itoa(num));
*/