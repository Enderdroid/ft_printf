/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 03:58:59 by tkleiner          #+#    #+#             */
/*   Updated: 2020/05/26 15:46:35 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_getlen(long long int num)
{
	size_t		len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		len++;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(long long int n)
{
	char			*str;
	int				i;
	int				min;

	min = 0;
	i = ft_getlen(n);
	if (!(str = ft_calloc(i + 1, sizeof(char))))
		return (NULL);
	str[i] = '\0';
	str[0] = '0';
	if (n == 0)
		return (str);
	if (n < 0)
	{
		str[0] = '-';
		min = 1;
	}
	while (i > min)
	{
		str[--i] = '0' + (char)((n % 10) * ((min * -2) + 1));
		n /= 10;
	}
	return (str);
}
