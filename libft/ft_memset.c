/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 04:38:22 by jwebb             #+#    #+#             */
/*   Updated: 2016/11/30 18:08:52 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp;
	unsigned char	ch;
	size_t			i;

	temp = (unsigned char *)b;
	ch = (unsigned char)c;
	i = 0;
	while (len-- > 0)
		temp[i++] = ch;
	return (temp);
}
