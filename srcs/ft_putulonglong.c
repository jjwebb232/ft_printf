/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putulonglong.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <jwebb@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 22:44:56 by jwebb             #+#    #+#             */
/*   Updated: 2017/05/31 11:49:34 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static unsigned long long	ft_printulonglong(unsigned long long n,
		unsigned long long l)
{
	int					i;
	unsigned long long	temp;
	
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

void						ft_putulonglong(unsigned long long n)
{
	unsigned long long	l;

	l = 1;
	if (n == ULLONG_MAX)
	{
		ft_putulonglong(n / 10);
		ft_putulonglong(n % 10);
		return ;
	}
	while (n / l > 9)
		l *= 10;
	while (l > 0)
	{
		n -= ft_printulonglong(n, l);
		l /= 10;
	}
}
