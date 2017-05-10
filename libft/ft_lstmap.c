/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:57:39 by jwebb             #+#    #+#             */
/*   Updated: 2016/11/30 23:59:32 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;

	if (!lst || !f)
		return (NULL);
	new = (t_list *)ft_memalloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new = f(lst);
	if (lst->next)
		new->next = ft_lstmap(lst->next, f);
	return (new);
}
