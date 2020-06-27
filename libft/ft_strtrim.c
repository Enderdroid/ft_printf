/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 04:18:00 by tkleiner          #+#    #+#             */
/*   Updated: 2020/05/21 05:13:06 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*s_res;

	if (!s1)
		return (NULL);
	start = (char*)s1;
	while (*start && ft_strchr(set, *start))
		++start;
	if (!(*start))
	{
		s_res = ft_calloc(1, sizeof(char));
		return (s_res);
	}
	end = (char*)(s1 + ft_strlen(s1) - 1);
	while (end > start && ft_strchr(set, *end))
		--end;
	s_res = ft_substr(s1, start - s1, end - start + 1);
	return (s_res);
}
