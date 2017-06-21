/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matxpoint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 09:57:26 by jwebb             #+#    #+#             */
/*   Updated: 2017/03/17 09:59:43 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_matxpoint(float mat[4][4], t_coords *coords)
{
	int x;
	int y;

	x = coords->x * mat[0][0] + coords->y * mat[0][1] +
		coords->z * mat[0][2] + mat[0][3];
	y = coords->x * mat[1][0] + coords->y * mat[1][1] +
		coords->z * mat[1][2] + mat[1][2];
	coords->x = x;
	coords->y = y;
}
