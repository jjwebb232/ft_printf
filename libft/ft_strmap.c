/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:49:08 by jwebb             #+#    #+#             */
/*   Updated: 2016/11/30 19:46:55 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	l;
	unsigned int	i;
	char			*str;

	l = 0;
	i = 0;
	if (s)
	{
		while (s[l])
			l++;
		str = (char *)ft_memalloc(l + 1);
		if (!str)
			return (NULL);
		while (s[i])
		{
			str[i] = f(s[i]);
			i++;
		}
		return (str);
	}
	return (NULL);
}
