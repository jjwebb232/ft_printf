/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <jwebb@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 01:01:12 by jwebb             #+#    #+#             */
/*   Updated: 2017/06/19 05:35:48 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*edge_handler(char *str, long nbr)
{
	if (nbr == LONG_MIN)
	{
		str = ft_memalloc(20);
		str = ft_strcpy(str, "-9223372036854775808");
		return (str);
	}
	if (!nbr)
	{
		str = ft_memalloc(1);
		ft_strcpy(str, "0");
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

	str = NULL;
	if ((str = edge_handler(str, nbr)))
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
