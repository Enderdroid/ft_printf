/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 04:08:17 by tkleiner          #+#    #+#             */
/*   Updated: 2020/05/26 15:36:50 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	size_t			i;

	src = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (src[i] == (unsigned char)c)
			return ((void*)&src[i]);
		++i;
	}
	return (NULL);
}
