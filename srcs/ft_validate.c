#include "srcs/libftprintf.h"

int		ft_validate(t_sarg *pref)
{
	const	char	type[] = "dicspuxXnfeg";
	if (ft_strchr(type, pref->type))
		return(1);
	return(0);
}
