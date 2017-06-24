/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <jwebb@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 22:44:56 by jwebb             #+#    #+#             */
/*   Updated: 2017/06/21 14:06:25 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_printlong(long long n, long l)
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

void		edge_handler(long n)
{
	ft_putlong(n / 10);
	if (n < 0)
		ft_putlong(-(n % 10));
	else
		ft_putlong(n % 10);
}

void		ft_putlong(long n)
{
	long		l;
	long		min;

	l = 1;
	min = 9223372036854775807;
	++min;
	if (n == 9223372036854775807 || n == min)
	{
		edge_handler(n);
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
		n -= ft_printlong(n, l);
		l /= 10;
	}
}
