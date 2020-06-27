#include "srcs/libftprintf.h"

static	int	ft_fparse(const char *src, char *flags)//NO PTR
{
	int		i;
	int		dif;
	char	*c;
	const	char	g_flags[] = " #%+-0";

	i = 0;
	dif = 0;
	while ((c = ft_strchr(g_flags, src[dif++])))
		if (!(ft_strchr(flags, *c)))
			flags[i++] = *c;
	if ((c = ft_strchr(flags, ' ')) && ft_strchr(flags, '+'))
		ft_rmchar(c);
	if ((c = ft_strchr(flags, '0')) && ft_strchr(flags, '-'))
		ft_rmchar(c);
	return (--dif);
}

static	int	ft_wparse(char *start, long long *width)//NO PTR
{
	int		dif;

	dif = 0;
	if (*start == '*')
	{
		*width = -2;
		return (1);
	}
	else if (*start == '.')
	{
		*width = 0;
		return (0);
	}
	else
	{
		*width = ft_atoi(start);
		while (ft_isdigit(start[dif]))
			++dif;
	}
	return (dif);
}

static	int	ft_pparse(char *start, long long *perc)//NO PTR
{
	int		dif;

	dif = 0;
	if (*start == '*')
	{
		*perc = -2;
		return (1);
	}
	else
	{
		*perc = ft_atoi(start);
		while (ft_isdigit(start[dif]))
			++dif;
	}
	return (dif);
}

static	int	ft_mparse(char *start, char *mode)//NO PTR
{
	int		dif;

	dif = 0;
	if (*start == 'l')
	{
		*mode = ++dif;
		if (*(start + 1) == 'l')
			*mode = ++dif;
	}
	else if (*start == 'h')
	{
		*mode = 2 + (++dif);
		if (*(start + 1) == 'h')
			*mode = 2 + (++dif);
	}
	return (dif);
}

int			ft_parse(const char *src, va_list *factor, t_sarg *pref)//NO PTR
{
	int		dif;

	dif = 0;
	dif = ft_fparse(src, pref->flags);
	dif += ft_wparse((char*)(src + dif), &(pref->width));
	if (pref->width == -2)
		pref->width = va_arg(*factor, int);
	if (*(src + dif) == '.')
		dif += ft_pparse((char*)(src + (dif + 1)), &(pref->perc)) + 1;
	if (pref->perc == -2)
		pref->perc = va_arg(*factor, int);
	dif += ft_mparse((char*)(src + dif), &(pref->mode));
	pref->type = *(src + dif);
	return (dif);
}