/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 04:11:44 by tkleiner          #+#    #+#             */
/*   Updated: 2020/05/24 04:23:03 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					ft_putnbr_fd(int n, int fd)
{
	long long int	nb;
	long long int	buf;
	long long int	div;

	nb = (long long int)ft_abs(n);
	if (nb == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (n < 0)
		ft_putchar_fd('-', fd);
	div = 1000000000;
	while (nb / div == 0 && div != 0)
		div /= 10;
	while (div > 0)
	{
		buf = nb / div;
		nb -= buf * div;
		ft_putchar_fd((char)(buf + '0'), fd);
		div = div / 10;
	}
}
