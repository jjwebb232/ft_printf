/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 10:07:04 by jwebb             #+#    #+#             */
/*   Updated: 2016/12/01 03:47:58 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	if (str1[i] == '\0' || str2[i] == '\0')
	{
		if (str1[i] == '\0')
			return (-str2[i]);
		if (str2[i] == '\0')
			return (str1[i]);
	}
	while (str1[i] == str2[i] && str1[i] && str2[i] && --n > 0)
		i++;
	return (str1[i] - str2[i]);
}
