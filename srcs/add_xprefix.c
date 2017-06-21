/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_xprefix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <jwebb@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 11:32:40 by jwebb             #+#    #+#             */
/*   Updated: 2017/06/21 11:32:54 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		add_xprefix(char **str)
{
	char	*tmp;

	tmp = (char*)ft_memalloc(ft_strlen(*str) + 2);
	tmp = ft_strcat(tmp, "0x");
	tmp = ft_strcat(tmp, *str);
	ft_memdel((void**)str);
	*str = (char*)ft_memalloc(ft_strlen(tmp));
	*str = ft_strcpy(*str, tmp);
	ft_memdel((void**)&tmp);
	return (2);
}
