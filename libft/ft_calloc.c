/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 03:57:37 by tkleiner          #+#    #+#             */
/*   Updated: 2020/05/24 04:23:23 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t num, size_t size)
{
	void	*alloc;

	alloc = malloc(num * size);
	if (!alloc)
		return (NULL);
	ft_bzero(alloc, num * size);
	return (alloc);
}
