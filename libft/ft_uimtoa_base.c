/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uimtoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <jwebb@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 01:01:12 by jwebb             #+#    #+#             */
/*   Updated: 2017/04/27 10:20:50 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uimtoa_base(intmax_t nbr, int base)
{
	char			*str;
	int				l;
	uintmax_t		n;

	n = nbr;
	l = 1;
	if (!n)
		return ("0");
	while ((n /= base))
		++l;
	n = nbr;
	str = (char*)ft_memalloc(l + 1);
	str[l] = '\0';
	while (n)
	{
		str[--l] = n % base + '0';
		if (str[l] > '9')
			str[l] += 'a' - '0';
		n /= base;
	}
	return (str);
}
