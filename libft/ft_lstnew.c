/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 01:55:49 by jwebb             #+#    #+#             */
/*   Updated: 2016/11/30 22:22:11 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *list;

	list = (t_list *)ft_memalloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = ft_memalloc(content_size);
	if (!list->content)
		return (NULL);
	if (!content)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		ft_memcpy((void *)list->content, content, content_size);
		list->content_size = content_size;
	}
	list->next = NULL;
	return (list);
}
