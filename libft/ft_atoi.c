/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 03:57:21 by tkleiner          #+#    #+#             */
/*   Updated: 2020/05/23 21:02:21 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int					ft_atoi(const char *str)
{
	char			sign;
	long long int	num;
	unsigned char	*s;
	int				i;

	sign = 1;
	num = 1;
	i = 0;
	s = (unsigned char *)str;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		++i;
	if (s[i] == '+' || s[i] == '-')
	{
		sign *= (-1) * (s[i] / 45) + 1 * (43 / s[i]);
		++i;
	}
	if (s[i] >= '0' && s[i] <= '9')
		num *= (long long int)(s[i] - '0');
	else
		return (0);
	while (s[++i] >= '0' && s[i] <= '9')
		num = num * 10 + (long long int)(s[i] - '0');
	return ((int)(num * sign));
}
