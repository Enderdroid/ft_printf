/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 03:59:08 by tkleiner          #+#    #+#             */
/*   Updated: 2020/05/21 05:11:25 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*buf;

	if (!new || !lst)
		return ;
	buf = ft_lstlast(*lst);
	if (buf)
		buf->next = new;
	else
		*lst = new;
}
