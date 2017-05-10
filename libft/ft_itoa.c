/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 03:53:37 by jwebb             #+#    #+#             */
/*   Updated: 2016/11/30 21:25:24 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_chk_neg(int n, int i)
{
	if (n < 0)
	{
		if (i == 1)
			return (1);
		else
			return (0);
	}
	if (i == 1)
		return (0);
	return (2);
}

static char	ft_set_t(int l, int j, long temp)
{
	char *str;

	str = "0123456789";
	if (l == j)
		return (str[temp]);
	return (str[0]);
}

static char	*ft_ita(long n, int l, char *t, int i)
{
	long	temp;
	int		k;
	int		j;

	while (l > 0)
	{
		j = 1;
		temp = n;
		while (temp > 9)
		{
			temp /= 10;
			j++;
		}
		t[i++] = (ft_set_t(l, j, temp));
		if (--l == j - 1)
		{
			k = l + 1;
			j = 1;
			while (--k > 0)
				j *= 10;
			n -= j * temp;
		}
	}
	t[i] = '\0';
	return (t);
}

char		*ft_itoa(int n)
{
	long	num;
	int		i;
	int		l;
	char	*t;

	if (n == -2147483648)
	{
		t = (char *)ft_memalloc(sizeof(char) * 11 + 1);
		t = ft_strncat(t, "-2147483648", 12);
		return (t);
	}
	num = n * (-1 + ft_chk_neg(n, 0));
	i = 0 + ft_chk_neg(n, 1);
	l = ft_nbrlen(num);
	t = (char *)ft_memalloc((sizeof(char) * (l + i)) + 1);
	if (!t)
		return (NULL);
	if (i != 0)
		t[0] = '-';
	ft_ita(num, l, t, i);
	return (t);
}
