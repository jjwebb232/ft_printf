/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 08:59:26 by jwebb             #+#    #+#             */
/*   Updated: 2016/12/01 03:44:18 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	a;

	i = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	a = (unsigned char)c;
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == a)
			return (&dst[++i]);
		i++;
	}
	return (NULL);
}
