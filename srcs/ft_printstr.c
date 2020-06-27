#include "srcs/libftprintf.h"

static	void	ft_put_minus(int *is_minus)
{
	if (*is_minus)
	{
		ft_putchar_fd(*is_minus, 1);
		*is_minus = 0;
	}
}

static	char	*ft_put_s(char *pattern, char *arg, int *is_minus, int is_z)
{
	if (*pattern == 's')
	{
		++pattern;
		ft_put_minus(is_minus);
		if (is_z)
			ft_putchar_fd(*arg, 1);
		else
			ft_putstr_fd(arg, 1);
	}
	return (pattern);
}

static char		*ft_put_n(char *pattern, int *is_minus, char *printable)
{
	while (*pattern >= '0' && *pattern <= '9')
			++pattern;
	if (*pattern == 'z')
	{
		ft_put_minus(is_minus);
		*printable = '0';
	}
	else if (*pattern == ' ')
		*printable = ' ';
	return (++pattern);
}

void			ft_printstr(char *pattern, char *arg, int is_z)
{
	size_t		len;
	char		printable;
	int			is_minus;

	is_minus = 0;
	if ((*arg == '-' || *arg == ' ' || *arg == '+') && !is_z)
		is_minus = *(arg++);
	while (*pattern)
	{
		pattern = ft_put_s(pattern, arg, &is_minus, is_z);
		len = 0;
		if ((len = ft_atoi(pattern)))
		{
			pattern = ft_put_n(pattern, &is_minus, &printable);
			//printf("%i\n", len);
			//printf("\n\np: %s\n\n", pattern);
			while (len--)
			{
				ft_putchar_fd(printable, 1);
			}
		}
	}
}
