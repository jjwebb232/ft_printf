/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsize_t.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <jwebb@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 22:44:56 by jwebb             #+#    #+#             */
/*   Updated: 2017/05/31 10:24:08 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static long	ft_printlong(long long n, size_t l)
{
	int					i;
	size_t				temp;
	
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

void	ft_putsize_t(size_t n)
{
	size_t				l;
	unsigned long long	min;

	l = 1;
	min = 9223372036854775808ULL;
	if (n == 9223372036854775807 || n == min)
	{
		ft_putlong(n / 10);
		ft_putlong(n % 10);
		return ;
	}
	while (n / l > 9)
		l *= 10;
	while (l > 0)
	{
		n -= ft_printlong(n, l);
		l /= 10;
	}
}
