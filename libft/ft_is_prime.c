/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:41:32 by jwebb             #+#    #+#             */
/*   Updated: 2016/11/29 15:21:44 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int n)
{
	int i;

	i = 3;
	if (n == 2)
		return (1);
	if (n < 2 || n % 2 == 0)
		return (0);
	while (i < n)
	{
		if (n % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}
