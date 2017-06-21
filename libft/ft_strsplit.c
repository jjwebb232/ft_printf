/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 19:30:16 by jwebb             #+#    #+#             */
/*   Updated: 2016/12/02 05:32:13 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_split(char const *s, char **list, const char c, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	p;

	i = 0;
	p = 0;
	while (i < len)
	{
		while (s[p] == c)
			p++;
		if (!(list[i] = (char *)ft_memalloc(ft_wordlen(&s[p], c) + 1)))
			return ;
		j = 0;
		while (s[p] && s[p] != c)
			list[i][j++] = s[p++];
		list[i++][j] = 0;
	}
	list[i] = 0;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**list;
	size_t	len;

	if (!s || !c)
		return (NULL);
	len = ft_wordcount(s, c);
	if (!(list = (char **)ft_memalloc(sizeof(list) * len + 1)))
		return (NULL);
	ft_split(s, list, c, len);
	return (list);
}
