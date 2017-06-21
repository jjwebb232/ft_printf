/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <jwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 02:43:26 by jwebb             #+#    #+#             */
/*   Updated: 2017/04/18 14:07:04 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*itoh(long n, char *ptr)
{
	int	i;

	i = 8;
	while (n && --i >= 0)
	{
		ptr[i] = (n % 16) + '0';
		n /= 16;
		if (ptr[i] > '9')
			ptr[i] += 39;
	}
	return (ptr);
}

char		*ft_itoh(long n)
{
	char	*ptr;
	int		i;

	if (n <= 0)
		return ("0");
	ptr = ft_memalloc(8);
	i = -1;
	while (++i < 8)
		ptr[i] = '0';
	ptr[8] = '\0';
	ptr = itoh(n, ptr);
	while (*ptr == '0')
		++ptr;
	return (ptr);
}
