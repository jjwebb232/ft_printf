/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imtoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <jwebb@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 01:01:12 by jwebb             #+#    #+#             */
/*   Updated: 2017/05/10 06:44:04 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_imtoa_base(intmax_t n, int base)
{
	char			*str;
	int				l;

	l = 1;
	if (!n)
		return ("0");
	while ((n /= base))
		++l;
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
