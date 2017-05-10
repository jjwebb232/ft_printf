/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matscale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 09:57:26 by jwebb             #+#    #+#             */
/*   Updated: 2017/03/17 09:59:43 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_matscale(float mat[4][4], float x, float y, float z)
{
	float xyz[4][4];
	float tmp[4][4];

	ft_matidentity(xyz);
	xyz[0][0] = x;
	xyz[1][1] = y;
	xyz[2][2] = z;
	ft_matmultiply(xyz, mat, tmp);
	ft_matidentity(xyz);
	ft_matmultiply(xyz, tmp, mat);
}
