/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 02:43:26 by jwebb             #+#    #+#             */
/*   Updated: 2017/06/19 05:12:56 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"
# define NUM_FLAGS (flags->d || flags->D || flags->i || flags->u || flags->U)
# define HEX_FLAGS (flags->x || flags->X || flags->o || flags->p)
# define MOD_FLAGS (MODS1 || MODS2)
# define MODS1 (flags->hash || flags->left || flags->sign)
# define MODS2 (flags->zero || flags->dot || flags->space || flags->buff)
# define NOFREE_FLAGS (NUM_FLAGS || (HEX_FLAGS

typedef struct	s_flag
{
	unsigned int	arg:1;
	unsigned int	pcent:1;
	unsigned int	alt:1;
	unsigned int	a:1;
	unsigned int	A:1;
	unsigned int	c:1;
	unsigned int	d:1;
	unsigned int	D:1;
	unsigned int	e:1;
	unsigned int	E:1;
	unsigned int	f:1;
	unsigned int	F:1;
	unsigned int	g:1;
	unsigned int	G:1;
	unsigned int	h:1;
	unsigned int	hh:1;
	unsigned int	i:1;
	unsigned int	j:1;
	unsigned int	l:1;
	unsigned int	ll:1;
	unsigned int	L:1;
	unsigned int	n:1;
	unsigned int	o:1;
	unsigned int	O:1;
	unsigned int	p:1;
	unsigned int	s:1;
	unsigned int	S:1;
	unsigned int	u:1;
	unsigned int	U:1;
	unsigned int	x:1;
	unsigned int	X:1;
	unsigned int	z:1;
	unsigned int	hash:1;
	unsigned int	zero:1;
	unsigned int	left:1;
	unsigned int	sign:1;
	unsigned int	space:1;
	unsigned int	dot:1;
	unsigned int	buff;
	unsigned int	prec;
	int				ret;
}				t_flag;

typedef	struct	s_va
{
	int			args;
	const void	*arg;
	va_list		ap;
}				t_va;

int				is_arg(const char c);
void			print_args(const void *arg, t_flag *flags);
int				set_args(t_flag *flags, const char *str);
int				ft_printf(const char *str, ...);
int				ft_strmethod(const void *arg, t_flag *flags);
#endif
