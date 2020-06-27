#include "srcs/libftprintf.h"

t_sarg	*ft_reset(t_sarg *pref)
{
	pref->width = 0;
	pref->perc = -1;
	pref->mode = 0;
	pref->type = 0;
	ft_memset(pref->flags, 0, 7);
	return (pref);
}
