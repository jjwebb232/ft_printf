/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <jwebb@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 22:57:20 by jwebb             #+#    #+#             */
/*   Updated: 2017/06/24 10:57:27 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_addwstr(char **str, wchar_t *ws)
{
	int		i;
	char	*wc;

	i = -1;
	if (str && !*str)
		*str = ft_memalloc(2);
	while (ws[++i])
	{
		if (!(wc = ft_getwchar(ws[i])))
			return ;
		*str = (char *)ft_realloc(*str, ft_strlen(*str) + ft_strlen(wc));
		*str = ft_strcat(*str, wc);
		ft_memdel((void**)&wc);
	}
}
