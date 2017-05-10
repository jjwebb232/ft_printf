/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 04:26:44 by jwebb             #+#    #+#             */
/*   Updated: 2016/12/01 00:48:33 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (dst[i] && i < size)
		i++;
	if (i == size)
		return (i + ft_strlen(src));
	while (src[j] && i + 1 < size)
		dst[i++] = src[j++];
	dst[i] = '\0';
	if (src[j])
		while (src[j++])
			i++;
	return (i);
}
