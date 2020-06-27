/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 04:12:38 by tkleiner          #+#    #+#             */
/*   Updated: 2020/05/21 17:17:08 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strchr(const char *str, int ch)
{
	const char		*src;
	unsigned int	i;

	src = str;
	i = 0;
	while (src[i] != '\0')
	{
		if (src[i] == ch)
		{
			src = &src[i];
			return ((char*)src);
		}
		++i;
	}
	if (src[i] == ch)
	{
		src = &src[i];
		return ((char*)src);
	}
	return (NULL);
}
