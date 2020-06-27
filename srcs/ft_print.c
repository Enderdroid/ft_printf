#include "srcs/libftprintf.h"

static LONG_T ft_umod(t_sarg *pref, LONG_T val)
{
	if (!pref->mode)
		val = (size_t)val;
	if (pref->mode == 4)
		val = val & 255;
	else if (pref->mode == 3)
		val = val & 65535;
	else if (pref->mode == 1)
		val = (unsigned long int)val;
	return (val);
}

static long long int ft_imod(t_sarg *pref, va_list *factor)
{
	long long int	val;

	if (!pref->mode)
		val = (long long int)va_arg(*factor, int);
	else if (pref->mode == 4)
		val = (long long int)((char)(va_arg(*factor, int)));
	else if (pref->mode == 3)
		val = (long long int)((short int)(va_arg(*factor, int)));
	else if (pref->mode == 1)
		val = (long long int)va_arg(*factor, long int);
	else if (pref->mode == 2)
		val = va_arg(*factor, long long int);
	return (val);
}

int ft_print(t_sarg *pref, va_list *factor, int *ret)//NO PTR
{
	int buf;

	buf = *ret;
	if (pref->type == 'i' || pref->type == 'd')
		*ret += ft_print_i(pref, ft_imod(pref, factor));
	else if (pref->type == 'c')
		*ret += ft_print_c(pref, (char)va_arg(*factor, int));
	else if (pref->type == 'u')
		*ret += ft_print_u(pref, ft_umod(pref, va_arg(*factor, LONG_T)));
	else if (pref->type == 's')
		*ret += ft_print_s(pref, va_arg(*factor, char*));
	else if (pref->type == 'x' || pref->type == 'X')
		*ret += ft_print_hex(pref, ft_umod(pref, va_arg(*factor, LONG_T)));
	else if (pref->type == 'p')
		*ret += ft_print_hex(pref, va_arg(*factor, LONG_T));
	else
		return (0);
	if (*ret < buf)
		return (-1);
	return (*ret);
}