/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <jwebb@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 22:56:49 by jwebb             #+#    #+#             */
/*   Updated: 2017/06/21 12:51:13 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getwchar(wchar_t wc)
{
	char	*s;
	int		len;

	if (!(s = (char *)ft_memalloc(4)))
		return (NULL);
	len = ft_wctomb(s, wc);
	if (len < 1)
		ft_memdel((void**)&s);
	return (s);
}
