/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 19:02:45 by jwebb             #+#    #+#             */
/*   Updated: 2016/11/30 20:06:08 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	str = (char *)ft_memalloc(len + 1);
	i = 0;
	if (!str)
		return (NULL);
	if (s)
		while (len > 0)
		{
			str[i++] = s[start++];
			len--;
		}
	return (str);
}
