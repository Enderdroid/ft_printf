#include "libft.h"

void	ft_rmchar(char *c)
{
	if (!c || !(*c))
		return ;
	while (*c)
	{
		*c = *(c + 1);
		++c;
	}
}