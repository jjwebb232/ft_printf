/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 09:57:26 by jwebb             #+#    #+#             */
/*   Updated: 2017/03/17 09:59:43 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	mat_rot(float mat[4][4], float x, int a, int b)
{
	ft_matidentity(mat);
	mat[a][a] = cos(x);
	if (a == 0 && b == 2)
		mat[a][b] = -sin(x);
	else
		mat[a][b] = sin(x);
	mat[b][a] = -mat[a][b];
	mat[b][b] = mat[a][a];
}

void		ft_matrotate(float mat[4][4], float psi, float phi, float theta)
{
	float rotx[4][4];
	float roty[4][4];
	float rotz[4][4];
	float mat1[4][4];
	float mat2[4][4];

	mat_rot(rotx, theta, 1, 2);
	mat_rot(roty, phi, 0, 2);
	mat_rot(rotz, psi, 0, 1);
	ft_matmultiply(mat, roty, mat1);
	ft_matmultiply(mat1, rotx, mat2);
	ft_matmultiply(mat2, rotz, mat);
}
