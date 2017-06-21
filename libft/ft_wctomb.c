/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctomb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <jwebb@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 03:31:46 by jwebb             #+#    #+#             */
/*   Updated: 2017/06/20 13:03:47 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <wchar.h>

static void	fill_table(int *table)
{
	table[0] = 0x3f;
	table[1] = 0x80;
	table[2] = 0xC0;
	table[3] = 0xE0;
	table[4] = 0xF0;
}

static int	get_wc_len(wint_t wc)
{
	if (wc <= 0x7F)
		return (1);
	if (wc >= 0x80 && wc <= 0x7FF)
		return (2);
	if (wc >= 0x800 && wc <= 0xFFFF)
		return (3);
	if (wc > 0x10000 && wc <= 0x10FFFF)
		return (4);
	return (0);
}

int			ft_wctomb(char *s, wchar_t wc)
{
	int len;
	int	i;
	int table[5];

	if (!s)
		return (0);
	if (!(len = get_wc_len(wc)))
		return (-1);
	fill_table(&table[0]);
	i = -1;
	while (++i < len)
	{
		if (i == 0 && len == 1)
			s[i] = (wc);
		else if (i == 0)
			s[i] = (wc >> (6 * (len - 1)) | table[len]);
		else if (i < len - 1)
			s[i] = ((wc >> (6 * (len - 1 - i)) & table[0]) | table[1]);
		else
			s[i] = (wc & table[0]) | table[1];
	}
	return (len);
}
