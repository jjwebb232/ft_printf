/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuintmax_t.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <jwebb@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 22:44:56 by jwebb             #+#    #+#             */
/*   Updated: 2017/05/31 11:37:51 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static long	ft_printuintmax_t(uintmax_t n, uintmax_t l)
{
	int			i;
	uintmax_t	temp;
	
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

void	ft_putuintmax_t(uintmax_t n)
{
	uintmax_t	l;

	l = 1;
	if (n == UINTMAX_MAX)
	{
		ft_putintmax_t(n / 10);
		ft_putuintmax_t(n % 10);
		return ;
	}
	while (n / l > 9)
		l *= 10;
	while (l > 0)
	{
		n -= ft_printuintmax_t(n, l);
		l /= 10;
	}
}
