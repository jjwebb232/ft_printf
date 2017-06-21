/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 09:57:26 by jwebb             #+#    #+#             */
/*   Updated: 2017/03/17 09:59:43 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putpixel(t_pixel *pixel, t_mlx *mlx, int width, int height)
{
	if ((pixel->x > 0 && pixel->y > 0) &&
			(pixel->x < width && pixel->y < height))
	{
		mlx->addr[(pixel->x * 4) + (pixel->y * width * 4)] = pixel->blue;
		mlx->addr[(pixel->x * 4) + (pixel->y * width * 4) + 1] = pixel->green;
		mlx->addr[(pixel->x * 4) + (pixel->y * width * 4) + 2] = pixel->red;
	}
}
