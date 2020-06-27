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

static size_t	ft_getlen(long long int num)
{
	size_t		len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num *= -1;
		len++;
	}
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(long long int n)
{
	char			*str;
	long long int	num;
	size_t			i;

	num = n;
	i = ft_getlen(num);
	if (!(str = ft_calloc(i + 1, sizeof(char))))
		return (NULL);
	str[i] = '\0';
	str[0] = '0';
	if (num == 0)
		return (str);
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		str[--i] = '0' + (char)(num % 10);
		num /= 10;
	}
	return (str);
}
