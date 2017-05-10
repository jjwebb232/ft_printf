/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 02:43:26 by jwebb             #+#    #+#             */
/*   Updated: 2017/05/10 06:48:07 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"

typedef struct	s_flag
{
	int	arg:1;
	int	alt:1;
	int	a:1;
	int	A:1;
	int	c:1;
	int	d:1;
	int	D:1;
	int	e:1;
	int	E:1;
	int	f:1;
	int	F:1;
	int	g:1;
	int	G:1;
	int	h:1;
	int	hh:1;
	int	i:1;
	int	j:1;
	int	l:1;
	int	ll:1;
	int	L:1;
	int	n:1;
	int	o:1;
	int	O:1;
	int	p:1;
	int	s:1;
	int	S:1;
	int	u:1;
	int	U:1;
	int	x:1;
	int	X:1;
	int	z:1;
	int	hash:1;
	int	zero:1;
	int	left:1;
	int	sign:1;
	int	space:1;
	int	buff;
}				t_flag;

typedef	struct	s_va
{
	int			args;
	const char	*arg;
	va_list		ap;
}				t_va;

void			print_args(const char *arg, t_flag *flags);
int				set_args(t_flag *flags, const char *str);
int				ft_printf(const char *str, ...);
#endif
