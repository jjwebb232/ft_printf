/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cvrtnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 09:57:26 by jwebb             #+#    #+#             */
/*   Updated: 2017/03/17 09:59:43 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 	(new[max] - new[min]) (n - src[min])
**	------------------------------------	+	new[min]
**	       (src[max] - src[min])
*/

SIZE_LD	ft_cvrtnbr(SIZE_LD src[2], SIZE_LD new[2], SIZE_LD n)
{
	int max;
	int min;

	max = 1;
	min = 0;
	if (src[min] == src[max])
		return (src[min]);
	n = (((new[max] - new[min]) * (n - src[min])) / (src[max] - src[min]));
	n += new[min];
	return (n);
}
