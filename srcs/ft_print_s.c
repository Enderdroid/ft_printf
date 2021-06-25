/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 15:00:09 by tkleiner          #+#    #+#             */
/*   Updated: 2020/07/27 15:06:36 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/libftprintf.h"

int			ft_print_s(t_sarg *pref, char *s)
{
	char	*pattern;
	char	*buf;
	char	*s_buf;

	if (!pref->perc)
		s_buf = ft_strdup("");
	else if (!s)
		s_buf = ft_strdup("(null)");
	else
		s_buf = ft_strdup(s);
	if ((pref->perc >= 0) && (long long int)ft_strlen(s_buf) > pref->perc)
	{
		if (!(buf = ft_substr(s_buf, 0, pref->perc)))
			return (-1);
	}
	else
	{
		buf = ft_strdup(s_buf);
		pref->perc = -1;
	}
	if (!(pattern = ft_pattern(pref, ft_strlen(buf), ft_strlen(buf), 0)))
		return (ft_free_p(buf, s_buf, NULL, -1));
	ft_printstr(pattern, buf, 0);
	return (ft_free_p(buf, pattern, s_buf, 2));
}
