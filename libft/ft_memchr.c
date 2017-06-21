/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 07:40:27 by jwebb             #+#    #+#             */
/*   Updated: 2016/12/01 04:09:56 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	c2;

	i = 0;
	str = (unsigned char *)s;
	c2 = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == c2)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}
