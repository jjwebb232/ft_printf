/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 09:57:26 by jwebb             #+#    #+#             */
/*   Updated: 2017/03/17 09:59:43 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printline(t_line line, t_mlx *mlx, int width, int height)
{
	line.dx = abs(line.x - line.point.x);
	line.sx = line.point.x < line.x ? 1 : -1;
	line.dy = abs(line.y - line.point.y);
	line.sy = line.point.y < line.y ? 1 : -1;
	line.err = (line.dx > line.dy ? line.dx : -line.dy) / 2;
	while (1)
	{
		ft_putpixel(&line.point, mlx, width, height);
		if (line.point.x == line.x && line.point.y == line.y)
			break ;
		line.e2 = line.err;
		if (line.e2 > -line.dx)
		{
			line.err -= line.dy;
			line.point.x += line.sx;
		}
		if (line.e2 < line.dy)
		{
			line.err += line.dx;
			line.point.y += line.sy;
		}
	}
}
