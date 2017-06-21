/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <jwebb@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 01:01:12 by jwebb             #+#    #+#             */
/*   Updated: 2017/06/20 11:15:29 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*edge_handler(long nbr)
{
	char			*str;

	if (nbr == LONG_MIN)
	{
		str = (char*)ft_memalloc(21);
		str = ft_strcpy(str, "-9223372036854775808");
		return (str);
	}
	if (!nbr)
	{
		str = (char*)ft_memalloc(2);
		str[0] = '0';
		return (str);
	}
	return (NULL);
}

static char	*fill_str(char *str, long n, int l)
{
	while (n)
	{
		str[--l] = n % 10 + '0';
		n /= 10;
	}
	if (l == 1)
		str[0] = '-';
	return (str);
}

char		*ft_ltoa(long nbr)
{
	char			*str;
	int				l;
	long			n;

	if ((str = edge_handler(nbr)))
		return (str);
	l = 1;
	n = nbr;
	if (nbr < 0)
	{
		nbr *= -1;
		++l;
	}
	n = nbr;
	while ((n /= 10))
		++l;
	n = nbr;
	str = (char*)ft_memalloc(l + 1);
	str[l] = '\0';
	return (fill_str(str, n, l));
}
