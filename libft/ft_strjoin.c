/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 05:06:18 by jwebb             #+#    #+#             */
/*   Updated: 2016/11/30 20:14:38 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	int		l1;
	int		l2;

	l1 = 0;
	l2 = 0;
	if (s1)
		l1 = ft_strlen(s1);
	if (s2)
		l2 = ft_strlen(s2);
	tmp = (char *)ft_memalloc(sizeof(char) * (l1 + l2) + 1);
	if (!tmp)
		return (NULL);
	if (s1)
		tmp = ft_strncat(tmp, s1, l1);
	if (s2)
		tmp = ft_strncat(tmp, s2, l2);
	return (tmp);
}
