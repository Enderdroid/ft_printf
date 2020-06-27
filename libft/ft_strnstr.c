/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 04:17:50 by tkleiner          #+#    #+#             */
/*   Updated: 2020/05/26 15:37:06 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!(*little))
		return ((char*)big);
	while (i < len && big[i] != '\0')
	{
		j = 0;
		if (big[i] == little[j])
		{
			++j;
			while (little[j] != '\0' &&\
					big[i + j] == little[j] &&\
					(i + j) < len)
				++j;
			if (little[j] == '\0')
				return ((char*)&big[i]);
		}
		++i;
	}
	return (NULL);
}
