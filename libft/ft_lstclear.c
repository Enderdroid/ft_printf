/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 03:59:19 by tkleiner          #+#    #+#             */
/*   Updated: 2020/05/21 05:14:49 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*buf;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		buf = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = buf;
	}
}
