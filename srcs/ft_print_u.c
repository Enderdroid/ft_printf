/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 15:00:11 by tkleiner          #+#    #+#             */
/*   Updated: 2020/07/27 15:06:26 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/libftprintf.h"

static size_t		ft_gl(LONG_T num)
{
	size_t			len;

	len = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char				*ft_utoa(LONG_T n)
{
	char			*str;
	LONG_T			num;
	size_t			i;

	num = n;
	i = ft_gl(num);
	if (!(str = ft_calloc(i + 1, sizeof(char))))
		return (NULL);
	str[i] = '\0';
	str[0] = '0';
	if (num == 0)
		return (str);
	while (num > 0)
	{
		str[--i] = '0' + (char)(num % 10);
		num /= 10;
	}
	return (str);
}

int					ft_print_u(t_sarg *pref, LONG_T num)
{
	char			*arg;
	char			*s_num;
	char			minus;
	size_t			len;
	char			*pattern;

	arg = NULL;
	minus = 1;
	s_num = ft_utoa(num);
	if (pref->perc == 0 && num == 0)
		s_num[0] = '\0';
	if (ft_strchr(pref->flags, ' '))
		arg = ft_strjoin(" ", s_num);
	else if (ft_strchr(pref->flags, '+'))
		arg = ft_strjoin("+", s_num);
	else
		minus = 0;
	if (!arg && !(arg = ft_strdup(s_num)))
		return (-1);
	len = ft_strlen(arg);
	if (!(pattern = ft_pattern(pref, len, len - minus, 1)))
		return (ft_free_p(arg, NULL, s_num, -1));
	ft_printstr(pattern, arg, 0);
	return (ft_free_p(arg, pattern, s_num, 2));
}
