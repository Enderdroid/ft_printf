#include "srcs/libftprintf.h"

int			ft_printf(const char *s, ...)
{
	va_list	factor;
	t_sarg	*pref;
	char	*buf;
	int		ret;

	ret = 0;
	if (!(buf = (char*)s) || !(pref = (t_sarg*)malloc(sizeof(t_sarg))))
		return (-1);
	va_start(factor, s);
	while (*buf)
	{
		if (*buf == '%' && *(buf + 1) && *(++buf) != '%')
		{
			buf += ft_parse(buf, &factor, ft_reset(pref)) + 1;
			if (ft_validate(pref) && ft_print(pref, &factor, &ret) == -1)
					return (ft_free_p(pref, NULL, NULL, -1));
			else if (!ft_validate(pref))
				--buf;
		}
		else if (*buf)
			ret += ft_putchar(*(buf++), 1);
		printf("RET: %i\n", ret);
	}
	va_end(factor);
	ft_free_p(pref, NULL, NULL, 0);
	return (ret);
}

/*
[FLAGS](GOT)
	32		-- ' '
	35		-- '#'
	37		-- '%'
	43		-- '+'
	45		-- '-'
	48		-- '0'

[WIDTH](GOT)
	42		-- '*'
	48		-- '0'
	..
	57		-- '9'

[PRECISION](GOT)
	46		-- '.'
	42		-- '*'
	48		-- '0'
	..
	57		-- '9'

[MODIFIER]
	"l"		-- long
	"ll"	-- long long
	"h"		-- short
	"hh"	-- char(ultra short)
	"u"		-- unsigned (по умолчанию инт, но при наличии дальнейших приколов, думаю менять int в типе на тот тип, который дальше)
[CONVERSIONS]
	"d,i"	-- int										(1)
	"c"		-- char										(2)
	"s"		-- string									(3)
	"p"		-- pointer									(6)
	"x"		-- ui to hex "abcdef"						(4)
	"X"		-- ui to hex "ABCDEF"						(5)
	"%"		-- "%"										(0)
	"n"		-- *arg == ft_printf;						(10)
	"f"		-- float									(7)
	"e"		-- float with exp.							(8)
	"g"		-- float but with some stuff like "e"		(9)
*/
