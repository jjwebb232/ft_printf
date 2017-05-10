/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 09:57:26 by jwebb             #+#    #+#             */
/*   Updated: 2017/03/17 09:59:43 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_buildline(t_line *line, t_coords coords1, t_coords coords2, int c)
{
	ft_fillpixel(&line->point, coords1.x, coords1.y, c);
	line->x = coords2.x;
	line->y = coords2.y;
	line->dx = abs(line->x - line->point.x);
	line->sx = line->point.x < line->x ? 1 : -1;
	line->dy = abs(line->y - line->point.y);
	line->sy = line->point.y < line->y ? 1 : -1;
	line->err = (line->dx > line->dy ? line->dx : -line->dy) / 2;
}
