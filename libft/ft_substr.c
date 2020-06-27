/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 04:18:04 by tkleiner          #+#    #+#             */
/*   Updated: 2020/05/25 03:03:53 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	siz;

	if (!s)
		return (NULL);
	siz = ft_strlen(s);
	if (siz < start)
		return (ft_strdup(""));
	siz = ft_strlen(s + start);
	if (siz > len)
		siz = len;
	sub = ft_calloc(siz + 1, sizeof(char));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, siz + 1);
	sub[siz] = '\0';
	return (sub);
}
