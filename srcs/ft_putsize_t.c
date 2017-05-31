/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsize_t.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <jwebb@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 22:44:56 by jwebb             #+#    #+#             */
/*   Updated: 2017/05/31 11:07:15 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static long	ft_printsize_t(size_t n, size_t l)
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

	l = 1;;
	if (n == ULONG_MAX)
	{
		ft_putsize_t(n / 10);
		ft_putsize_t(n % 10);
		return ;
	}
	while (n / l > 9)
		l *= 10;
	while (l > 0)
	{
		n -= ft_printsize_t(n, l);
		l /= 10;
	}
}
