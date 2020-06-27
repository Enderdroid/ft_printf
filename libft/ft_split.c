/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 04:12:33 by tkleiner          #+#    #+#             */
/*   Updated: 2020/05/26 15:37:15 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_getsize(char const *s, char c)
{
	int			size;
	int			i;

	i = 0;
	if (!s || *s == '\0')
		return (1);
	while (s[i] == c)
		++i;
	if (s[i] == '\0')
		return (1);
	size = 0;
	while (s[++i] != '\0')
		if (s[i] == c && s[i - 1] != c)
			++size;
	if (s[i - 1] != c)
		++size;
	return (size + 1);
}

static int		ft_arrfill(char **arr, char const *s, char c, int i)
{
	int			j;

	j = 0;
	while (*s != c && *s)
		arr[i][j++] = (char)*s++;
	arr[i][j] = '\0';
	return (j);
}

static void		ft_delarr(char **arr, int size)
{
	int			i;

	i = 0;
	while (i < size)
	{
		free(arr[i]);
		arr[i] = NULL;
		++i;
	}
	free(arr);
	arr = NULL;
}

static int		ft_getlen(char const *s, char c)
{
	int			len;

	len = 0;
	while (*s != c && *s)
	{
		++len;
		++s;
	}
	++len;
	return (len);
}

char			**ft_split(char const *s, char c)
{
	char		**arr;
	int			i;

	i = 0;
	if (!s || !(arr = (char**)malloc(ft_getsize(s, c) * sizeof(char*))))
		return (NULL);
	arr[ft_getsize(s, c) - 1] = NULL;
	while (*s)
	{
		while (*s == c && *s)
			++s;
		if (*s != c && *s)
		{
			if (!(arr[i] = (char*)malloc(ft_getlen(s, c) * sizeof(char))))
			{
				ft_delarr(arr, i);
				return (NULL);
			}
			s += ft_arrfill(arr, s, c, i);
			++i;
		}
	}
	return (arr);
}
