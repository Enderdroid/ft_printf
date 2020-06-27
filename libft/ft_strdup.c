/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 04:16:17 by tkleiner          #+#    #+#             */
/*   Updated: 2020/05/21 05:12:43 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *str)
{
	char	*alloc;
	size_t	size;

	size = ft_strlen(str);
	alloc = ft_calloc(size + 1, sizeof(char));
	if (alloc == NULL)
		return (NULL);
	ft_strlcpy(alloc, str, size + 1);
	return (alloc);
}
