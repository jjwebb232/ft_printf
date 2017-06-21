/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:38:29 by jwebb             #+#    #+#             */
/*   Updated: 2016/12/01 02:18:13 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_printnbr_fd(long n, int l, int fd)
{
	int i;

	i = ft_nbrlen(l);
	while (i > 1)
	{
		n /= 10;
		i--;
	}
	n += 48;
	write(fd, &n, 1);
	n -= 48;
	n *= l;
	return (n);
}

void		ft_putnbr_fd(int n, int fd)
{
	int		l;
	long	nbr;

	l = 1;
	nbr = n;
	if (nbr < 0)
	{
		nbr *= -1;
		write(fd, "-", 1);
	}
	while (nbr / l > 9)
		l *= 10;
	while (l > 0)
	{
		nbr -= ft_printnbr_fd(nbr, l, fd);
		l /= 10;
	}
}
