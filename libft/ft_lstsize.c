/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 04:02:55 by tkleiner          #+#    #+#             */
/*   Updated: 2020/05/25 03:04:30 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_lstsize(t_list *lst)
{
	unsigned long	size;
	t_list			*buf;

	size = 0;
	if (!lst)
		return (size);
	buf = lst;
	while (buf)
	{
		buf = buf->next;
		++size;
	}
	return (size);
}
