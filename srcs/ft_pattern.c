/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pattern.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 15:00:01 by tkleiner          #+#    #+#             */
/*   Updated: 2020/07/27 15:08:14 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/libftprintf.h"

static int		ft_getwidth(t_sarg *pref, int a_size, int p_z_c, int *w_z_c)
{
	int			pa_size;
	int			s_res;

	pa_size = 0;
	s_res = 0;
	pa_size = a_size + p_z_c;
	if (ft_abs(pref->width) > (size_t)pa_size)
	{
		if (pref->width < 0)
			s_res = pref->width + pa_size;
		else
			s_res = pref->width - pa_size;
		if (ft_strchr(pref->flags, '0') && !ft_strchr(pref->flags, '-'))
			*w_z_c = s_res;
		if (ft_strchr(pref->flags, '-') && pref->width >= 0)
			return (s_res * -1);
		else
			return (s_res);
	}
	return (0);
}

static int		ft_getperc(t_sarg *pref, int a_size, int n_size)
{
	int			p_z_c;

	p_z_c = 0;
	if (a_size - 1 != n_size && n_size > pref->perc)
		p_z_c = pref->perc - n_size;
	else if (n_size < pref->perc && pref->perc != -1)
		p_z_c = pref->perc - n_size;
	else if (n_size == pref->perc || pref->perc == -1)
		p_z_c = 0;
	return (p_z_c);
}

static void		ft_sub_fp(char *str, int val, char c)
{
	char		*num;
	char		*sym;

	if (!(num = ft_itoa(val)))
	{
		*str = 'f';
		return ;
	}
	ft_strlcat(str, num, P_SIZE);
	free(num);
	num = NULL;
	if (!(sym = ft_calloc(2, sizeof(char))))
	{
		*str = 'f';
		return ;
	}
	*sym = c;
	ft_strlcat(str, sym, P_SIZE);
	free(sym);
	sym = NULL;
}

static void		ft_fillpattern(char *str, int w_s_c, int p_z_c, int w_z_c)
{
	int			is_zero;

	is_zero = 0;
	if (*str == '0' && ++is_zero)
	{
		if (w_s_c < 0)
			--w_s_c;
		if (w_s_c > 0)
			++w_s_c;
	}
	*str = 0;
	if (w_s_c > 0)
		ft_sub_fp(str, w_s_c, ' ');
	if (w_z_c > 0)
		ft_sub_fp(str, w_z_c, 'z');
	if (p_z_c > 0)
		ft_sub_fp(str, p_z_c, 'z');
	if (!is_zero)
		ft_strlcat(str, "s", P_SIZE);
	if (p_z_c < 0)
		ft_sub_fp(str, -p_z_c, 'z');
	if (w_s_c < 0)
		ft_sub_fp(str, -w_s_c, ' ');
}

char			*ft_pattern(t_sarg *pref, int a_size, int n_size, int is_perc)
{
	int			p_z_c;
	int			w_z_c;
	int			w_s_c;
	char		*str;

	w_z_c = 0;
	p_z_c = 0;
	if (!(str = ft_calloc(P_SIZE, sizeof(char))))
		return (NULL);
	if (pref->perc > 0 && is_perc)
		p_z_c = ft_getperc(pref, a_size, n_size);
	if (p_z_c < 0 && is_perc != -1)
		p_z_c = 0;
	w_s_c = ft_getwidth(pref, a_size, p_z_c, &w_z_c);
	if (is_perc && pref->perc >= 0)
		w_z_c = 0;
	else if (w_z_c && w_s_c > 0)
		w_s_c = 0;
	if (a_size == 0 && pref->width == 0)
		*str = '0';
	ft_fillpattern(str, w_s_c, p_z_c, w_z_c);
	if (ft_strchr(str, 'f'))
		return (NULL);
	return (str);
}
