/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:15:00 by jwebb             #+#    #+#             */
/*   Updated: 2016/11/30 19:29:05 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)ft_memalloc(size + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i <= size)
		ptr[i++] = '\0';
	return (ptr);
}
