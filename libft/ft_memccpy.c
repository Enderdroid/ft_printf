/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 04:07:49 by tkleiner          #+#    #+#             */
/*   Updated: 2020/05/23 02:50:47 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*dst;
	unsigned char	*s;
	size_t			i;

	i = 0;
	dst = (unsigned char*)dest;
	s = (unsigned char*)src;
	while (i < n)
	{
		if (s[i] == (unsigned char)c)
		{
			dst[i] = s[i];
			return ((void*)(dst + i + 1));
		}
		dst[i] = s[i];
		++i;
	}
	return (NULL);
}
