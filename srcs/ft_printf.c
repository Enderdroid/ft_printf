/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 15:00:23 by tkleiner          #+#    #+#             */
/*   Updated: 2020/07/27 15:04:37 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/libftprintf.h"

int			ft_printf(const char *s, ...)
{
	va_list	factor;
	t_sarg	*pref;
	int		ret;

	ret = 0;
	if (!(s) || !(pref = (t_sarg*)malloc(sizeof(t_sarg))))
		return (-1);
	va_start(factor, s);
	while (*s)
	{
		if (*s == '%' && *(s + 1) && *(++s) != '%')
		{
			s += ft_parse(s, &factor, ft_reset(pref)) + 1;
			if (ft_validate(pref) && ft_print(pref, &factor, &ret) == -1)
				return (ft_free_p(pref, NULL, NULL, -1));
			else if (!ft_validate(pref))
				--s;
		}
		else if (*s)
			ret += ft_putchar(*(s++), 1);
	}
	va_end(factor);
	ft_free_p(pref, NULL, NULL, 0);
	return (ret);
}
