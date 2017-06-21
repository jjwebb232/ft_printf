/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matmultiply.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 09:57:26 by jwebb             #+#    #+#             */
/*   Updated: 2017/03/17 09:59:43 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_matmultiply(float mat1[4][4], float mat2[4][4], float dst[4][4])
{
	int i;
	int j;
	int k;

	ft_matbzero(dst);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			k = -1;
			while (++k < 4)
				dst[i][j] += mat1[i][k] * mat2[k][j];
		}
	}
}
