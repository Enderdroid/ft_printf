/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 15:00:04 by tkleiner          #+#    #+#             */
/*   Updated: 2020/07/27 15:07:39 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/libftprintf.h"

int			ft_print_c(t_sarg *pref, char c)
{
	char	*arg;
	char	*pattern;

	if (!(arg = ft_calloc(2, sizeof(char))))
		return (-1);
	*arg = c;
	if (!(pattern = ft_pattern(pref, 1, 1, 0)))
		return (ft_free_p(arg, NULL, NULL, -1));
	ft_printstr(pattern, arg, 1);
	*arg = '1';
	return (ft_free_p(arg, pattern, NULL, 2));
}
