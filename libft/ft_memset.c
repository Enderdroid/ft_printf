/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 04:11:27 by tkleiner          #+#    #+#             */
/*   Updated: 2020/05/21 17:13:59 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *destination, int c, size_t n)
{
	char	*dst;
	size_t	i;

	dst = destination;
	i = 0;
	while (i < n)
	{
		dst[i] = c;
		++i;
	}
	return (dst);
}
