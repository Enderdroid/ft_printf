#include "srcs/libftprintf.h"

int	ft_print_s(t_sarg *pref, char *s)
{
	char *pattern;
	char *buf;

	if (!pref->perc || (!s && pref->perc != -1 && (size_t)pref->perc < ft_strlen("(null)")))
	{
		s = ft_strdup("");
		pref->perc = 0;
	}
	else if (!s)
		s = ft_strdup("(null)");
	if ((pref->perc >= 0) && (long long int)ft_strlen(s) > pref->perc)
	{	
		if (!(buf = ft_substr(s, 0, pref->perc)))
			return(-1);
	}
	else
	{
		buf = ft_strdup(s);
		pref->perc = -1;
	}
	if (!(pattern = ft_pattern(pref, ft_strlen(buf), ft_strlen(buf), 0)))
		return (ft_free_p(buf, NULL, NULL, -1));
	ft_printstr(pattern, buf, 0);
	return (ft_free_p(buf, pattern, NULL, 2));
}