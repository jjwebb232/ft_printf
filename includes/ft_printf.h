/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 02:43:26 by jwebb             #+#    #+#             */
/*   Updated: 2017/06/21 20:43:51 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"
# include "ansi.h"
# define NUM_FLAGS (flags->d || flags->ld || flags->i || flags->u || flags->lu)

typedef struct	s_flag
{
	unsigned int	arg:1;
	unsigned int	pcent:1;
	unsigned int	alt:1;
	unsigned int	c:1;
	unsigned int	d:1;
	unsigned int	ld:1;
	unsigned int	h:1;
	unsigned int	hh:1;
	unsigned int	i:1;
	unsigned int	j:1;
	unsigned int	l:1;
	unsigned int	ll:1;
	unsigned int	o:1;
	unsigned int	lo:1;
	unsigned int	p:1;
	unsigned int	r:1;
	unsigned int	s:1;
	unsigned int	ls:1;
	unsigned int	u:1;
	unsigned int	lu:1;
	unsigned int	x:1;
	unsigned int	xx:1;
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
int				set_args(t_flag *flags, const char *str);
int				ft_printf(const char *str, ...);
int				ft_printf_arg(const void *arg, t_flag *flags);
void			get_text(char **str, const void *arg, t_flag *flags);
void			get_nums(char **str, const void *arg, t_flag *flags);
void			get_special_nums(char **str, const void *arg, t_flag *flags);
void			apply_mods(char **str, t_flag *flags, const void *arg);
int				add_xprefix(char **str);
unsigned int	add_chars(char **str, char c, int len, t_flag *flags);

#endif
