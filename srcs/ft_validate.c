/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 15:00:37 by tkleiner          #+#    #+#             */
/*   Updated: 2020/07/27 15:04:17 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/libftprintf.h"

int				ft_validate(t_sarg *pref)
{
	const char	type[] = "dicspuxXnfeg%";

	if (ft_strchr(type, pref->type))
		return (1);
	return (0);
}
