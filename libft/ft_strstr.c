/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 17:37:37 by jwebb             #+#    #+#             */
/*   Updated: 2016/11/30 00:31:57 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cmp(int i, const char *big, const char *little)
{
	int j;

	j = 0;
	while (big[i] && little[j] && big[i] == little[j])
	{
		i++;
		j++;
		if (!little[j])
			return (1);
	}
	return (0);
}

char		*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		tmp;
	char	*ptr;

	if (!ft_strncmp(little, "", 1))
		return ((char *)&big[0]);
	i = 0;
	while (big[i])
	{
		if (big[i] && little[0] && big[i] == little[0])
			tmp = ft_cmp(i, big, little);
		if (tmp == 1)
		{
			ptr = (char *)&big[i];
			return (ptr);
		}
		i++;
	}
	return (NULL);
}
