/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlonglong.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <jwebb@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 22:44:56 by jwebb             #+#    #+#             */
/*   Updated: 2017/05/31 10:47:04 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static long	ft_printlonglong(long long n, long l)
{
	int		i;
	long	temp;
	
	i = 0;
	temp = l;
	while (temp && ++i)
		temp /= 10;
	while (--i)
		n /= 10;
	n += 48;
	write(1, &n, 1);
	n -= 48;
	return (n * l);
}

void	ft_putlonglong(long long n)
{
	long long	l;

	l = 1;
	if (n == LLONG_MIN || n == LLONG_MAX)
	{
		ft_putlong(n / 10);
		if (n < 0)
			ft_putlonglong(-(n % 10));
		else
			ft_putlonglong(n % 10);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
	}
	while (n / l > 9)
		l *= 10;
	while (l > 0)
	{
		n -= ft_printlonglong(n, l);
		l /= 10;
	}
}
