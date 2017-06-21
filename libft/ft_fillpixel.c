/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillpixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 09:57:26 by jwebb             #+#    #+#             */
/*   Updated: 2017/03/17 09:59:43 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_fillpixel(t_pixel *pixel, int x, int y, int c)
{
	pixel->x = x;
	pixel->y = y;
	pixel->blue = c;
	while (pixel->blue > 0xFFFF)
		pixel->blue -= 0x110000;
	while (pixel->blue > 0xFF)
		pixel->blue -= 0x001100;
	pixel->green = c - pixel->blue;
	while (pixel->green > 0xFF00)
		pixel->green -= 0x110000;
	pixel->red = c - pixel->green - pixel->blue;
	while (pixel->green > 0xFF)
		pixel->green -= 0x10ef;
	while (pixel->red > 0xFF)
		pixel->red -= 0x10ffef;
}
