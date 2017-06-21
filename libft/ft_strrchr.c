/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 18:40:44 by jwebb             #+#    #+#             */
/*   Updated: 2016/11/29 15:21:23 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = ft_strlen(s);
	if (s[i] == c)
		return (&str[i]);
	while (i > 0)
	{
		i--;
		if (s[i] == c)
			return (&str[i]);
	}
	return (NULL);
}
