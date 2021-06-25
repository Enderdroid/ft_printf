/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_reset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 15:00:33 by tkleiner          #+#    #+#             */
/*   Updated: 2020/07/27 15:00:33 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/libftprintf.h"

t_sarg	*ft_reset(t_sarg *pref)
{
	pref->width = 0;
	pref->perc = -1;
	pref->mode = 0;
	pref->type = 0;
	ft_memset(pref->flags, 0, 7);
	return (pref);
}
