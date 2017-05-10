/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 07:12:40 by jwebb             #+#    #+#             */
/*   Updated: 2016/11/21 07:22:37 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		l;
	char	*str;

	i = 0;
	l = 0;
	while (s1[l])
		l++;
	str = (char *)ft_memalloc(sizeof(char) * l + 1);
	if (!str)
		return (NULL);
	while (i <= l)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
