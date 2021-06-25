/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 21:30:09 by tkleiner          #+#    #+#             */
/*   Updated: 2020/07/27 21:30:10 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long int		ft_abs(long long int arg)
{
	unsigned long long int	val;

	if (arg < 0)
		val = arg * (-1);
	else
		val = arg;
	return (val);
}
