#include "libft.h"

unsigned long long int		ft_abs(long long int arg)
{
	unsigned long long int	val;
	if (arg < 0)
		val = arg * (-1);
	else
		val = arg;
	return(val);
}