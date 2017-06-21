/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putulong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <jwebb@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 22:44:56 by jwebb             #+#    #+#             */
/*   Updated: 2017/06/21 12:50:44 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static unsigned long	ft_printulong(unsigned long n, unsigned long l)
{
	int				i;
	unsigned long	temp;

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

void					ft_putulong(unsigned long n)
{
	unsigned long	l;

	l = 1;
	while (n / l > 9)
		l *= 10;
	while (l > 0)
	{
		n -= ft_printulong(n, l);
		l /= 10;
	}
}
