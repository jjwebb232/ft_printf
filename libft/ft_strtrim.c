/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 22:45:34 by jwebb             #+#    #+#             */
/*   Updated: 2016/12/01 06:43:32 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_trim(char const *s, char *str, unsigned int i, unsigned int l)
{
	int j;

	j = 0;
	if (s)
		while (l-- > 0)
			str[j++] = s[i++];
	return (str);
}

char		*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	l;
	unsigned int	e;
	char			*str;

	l = 0;
	if (s && (i = 0) == 0)
	{
		while (WHITESPACE(s[i]))
			i++;
		while (s[i + l] && !(WHITESPACE(s[i + l])))
		{
			e = 0;
			while (s[i + l] && !(WHITESPACE(s[i + l])))
				l++;
			while (WHITESPACE(s[i + l + e]))
				e++;
			if (s[i + l + e] != '\0')
				l += e;
		}
	}
	str = (char *)ft_memalloc(l + 1);
	if (!str)
		return (NULL);
	return (ft_trim(s, str, i, l));
}
