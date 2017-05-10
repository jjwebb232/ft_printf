/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:40:45 by jwebb             #+#    #+#             */
/*   Updated: 2016/11/29 13:53:53 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;
	t_list	*tmp;

	if (alst)
	{
		list = *alst;
		while (list != NULL)
		{
			tmp = list->next;
			del(list, list->content_size);
			list = tmp;
		}
		*alst = NULL;
	}
}
