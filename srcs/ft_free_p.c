/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 14:59:54 by tkleiner          #+#    #+#             */
/*   Updated: 2020/07/27 15:09:03 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/libftprintf.h"

static int	ft_getwholelen(char *arg, char *pattern)
{
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(arg);
	while (pattern[i])
	{
		len += ft_atoi(&pattern[i++]);
		while (pattern[i - 1] >= '0' && pattern[i - 1] <= '9')
			++i;
	}
	return (len);
}

int			ft_free_p(void *arg, void *pattern, void *o_str, int key)
{
	if (key == 2)
		key = ft_getwholelen(arg, pattern);
	if (arg)
		free(arg);
	if (pattern)
		free(pattern);
	if (o_str)
		free(o_str);
	return (key);
}
