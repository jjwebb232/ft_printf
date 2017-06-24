/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <jwebb@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 22:57:45 by jwebb             #+#    #+#             */
/*   Updated: 2017/06/24 11:18:23 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_addstr(char **str, char *s)
{
	if (str && *str)
		ft_memdel((void**)str);
	*str = (char *)ft_memalloc(ft_strlen(s));
	*str = ft_strcat(*str, s);
}
