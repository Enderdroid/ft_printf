/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 15:00:06 by tkleiner          #+#    #+#             */
/*   Updated: 2020/07/27 15:07:29 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/libftprintf.h"

static void		ft_itoa_hex(char **arg, t_sarg *pref, LONG_T num, char start)
{
	LONG_T		buf;
	size_t		len;
	char		*str;

	len = 0;
	str = ft_calloc(P_SIZE, sizeof(char));
	if (!str || !(*arg = str))
		return ;
	if (pref->type == 'p')
		str += 2;
	if (!(buf = num))
		*str = '0';
	while (++len && buf)
		buf /= 16;
	while (--len)
	{
		buf = num % 16;
		if (buf > 9)
			str[len - 1] = start - 10 + buf;
		else
			str[len - 1] = buf + '0';
		num = num / 16;
	}
}

int				ft_print_hex(t_sarg *pref, LONG_T num)
{
	char		*arg;
	char		*pattern;
	size_t		len;

	len = 0;
	arg = NULL;
	if (pref->type == 'p' && !(pref->perc)++)
		num = 0;
	if (pref->type == 'X' || pref->type == 'x')
		ft_itoa_hex(&arg, pref, num, pref->type - 23);
	else if (pref->type == 'p')
	{
		ft_itoa_hex(&arg, pref, num, 'a');
		ft_memcpy(arg, "0x", 2);
	}
	if (!arg)
		return (-1);
	if (!pref->perc && !num && pref->type != 'p')
		arg[0] = '\0';
	len = ft_strlen(arg);
	if (!(pattern = ft_pattern(pref, len, len, 1)))
		return (ft_free_p(arg, NULL, NULL, -1));
	ft_printstr(pattern, arg, 0);
	return (ft_free_p(arg, pattern, NULL, 2));
}
