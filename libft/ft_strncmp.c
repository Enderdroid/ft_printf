/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 04:17:42 by tkleiner          #+#    #+#             */
/*   Updated: 2020/05/21 14:49:08 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char	*us1;
	unsigned char	*us2;
	size_t			i;

	i = 0;
	if (n == 0)
		return (0);
	us1 = (unsigned char *)str1;
	us2 = (unsigned char *)str2;
	while (us1[i] == us2[i] && us1[i] && us2[i] && i < n - 1)
		++i;
	return (us1[i] - us2[i]);
}
