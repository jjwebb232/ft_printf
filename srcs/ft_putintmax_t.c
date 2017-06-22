/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putintmax_t.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <jwebb@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 22:44:56 by jwebb             #+#    #+#             */
/*   Updated: 2017/05/31 11:18:51 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static long	ft_printintmax_t(intmax_t n, intmax_t l)
{
	int			i;
	intmax_t	temp;
	
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

void	ft_putintmax_t(intmax_t n)
{
	intmax_t	l;

	l = 1;
	if (n == INTMAX_MIN || n == INTMAX_MAX)
	{
		ft_putintmax_t(n / 10);
		if (n < 0)
			ft_putintmax_t(-(n % 10));
		else
			ft_putintmax_t(n % 10);
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
		n -= ft_printintmax_t(n, l);
		l /= 10;
	}
}
