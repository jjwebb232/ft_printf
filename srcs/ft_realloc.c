/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:52:51 by jwebb             #+#    #+#             */
/*   Updated: 2017/01/19 12:29:45 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*temp;

	if (!size && ptr)
	{
		if (!(temp = malloc(1)))
			return (NULL);
		ft_memdel(&ptr);
		free(ptr);
		return (temp);
	}
	if (!(temp = malloc(size)))
		return (NULL);
	if (ptr)
	{
		ft_memcpy(temp, ptr, size);
		ft_memdel(&ptr);
		free(ptr);
	}
	return (temp);
}
