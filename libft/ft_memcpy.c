/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 04:08:35 by tkleiner          #+#    #+#             */
/*   Updated: 2020/05/23 02:42:00 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dst;
	unsigned char		*s;
	size_t				i;

	if (!src && !dest)
		return (NULL);
	dst = (unsigned char*)dest;
	s = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		dst[i] = s[i];
		++i;
	}
	return (dest);
}
