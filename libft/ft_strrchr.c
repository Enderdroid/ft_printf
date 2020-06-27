/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 04:17:54 by tkleiner          #+#    #+#             */
/*   Updated: 2020/05/21 05:20:50 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strrchr(const char *str, int ch)
{
	const char	*src;
	size_t		i;

	src = str;
	i = ft_strlen(str);
	while (i)
	{
		if (src[i] == ch)
		{
			src = &src[i];
			return ((char*)src);
		}
		--i;
	}
	if (src[i] == ch)
	{
		src = &src[i];
		return ((char*)src);
	}
	return (NULL);
}
