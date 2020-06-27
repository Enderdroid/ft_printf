/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 04:08:42 by tkleiner          #+#    #+#             */
/*   Updated: 2020/05/23 21:01:14 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dst;
	unsigned char		*s;
	size_t				i;

	if (dest == src || n == 0)
		return (dest);
	if (!dest && !src)
		return (NULL);
	dst = (unsigned char*)dest;
	s = (unsigned char*)src;
	i = n;
	if (dst > s)
	{
		while (--i)
			dst[i] = (unsigned char)s[i];
		dst[i] = s[i];
	}
	else
		ft_memcpy(dst, s, n);
	return (dest);
}
