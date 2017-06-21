/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <jwebb@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 14:53:39 by jwebb             #+#    #+#             */
/*   Updated: 2017/04/25 15:49:02 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_printunbr(unsigned long n, int l)
{
	int	i;
	int	tmp;

	tmp = l;
	i = ft_nbrlen(l);
	while (i > 1)
	{
		n /= 10;
		--i;
	}
	n += 48;
	write(1, &n, 1);
	n -= 48;
	return (n * l);
}

void		ft_putunbr(unsigned int n)
{
	int	l;

	l = 1;
	while (n / l > 9)
		l *= 10;
	while (l > 0)
	{
		n -= ft_printunbr(n, l);
		l /= 10;
	}
}
