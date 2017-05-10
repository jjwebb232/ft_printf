/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <jwebb@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 03:11:05 by jwebb             #+#    #+#             */
/*   Updated: 2017/05/10 06:43:29 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_buff(t_flag *flags)
{
	char	c;

	c = ' ';
	if (flags->zero && !flags->left)
		c = '0';
	while (flags->buff--)
		ft_putchar(c);
}

static void	chk_buff(t_flag *flags, int offset, long *n, int i)
{
	long	s;

	s = 0;
	if (flags->sign && ((i && (int)*n >= 0) || (!i && *n >= 0)))
		s = 1;
	if ((i && (int)*n < 0) || (!i && n < 0))
		s = -1;
	if (flags->space && !s && (flags->d || flags->i))
		ft_putchar(' ');
	if (flags->zero)
	{
		if (i && (int)*n < 0)
			*n = (int)*n * -1;
		if (n < 0)
			*n *= -1;
		if (s == -1)
			ft_putchar('-');
		if (s == 1)
			ft_putchar('+');
	}
	if (s)
		--flags->buff;
	flags->buff -= offset;
	if (!flags->left && flags->buff > 0)
		print_buff(flags);
	if (s == 1 && !flags->zero)
		ft_putchar('+');
}

static void	ox_handler(const char *arg, t_flag *flags)
{
	char	*str;
	int		i;

	if (flags->o || flags->O)
	{
		if (flags->O || (flags->l && flags->o))
			str = ft_ultoa_base((long)arg, 8);
		else
			str = ft_uitoa_base((long)arg, 8);
		chk_buff(flags, ft_strlen(str), 0, 0);
		if (flags->hash)
			ft_putnbr(0);
		ft_putstr(str);
	}
	else if ((flags->x || flags->X) && !flags->l)
	{
		if (flags->hash)
			flags->buff -= 2;
		if (flags->hash && flags->x)
			ft_putstr("0x");
		if (flags->hash && flags->X)
			ft_putstr("0X");
		str = ft_itoh((int)arg);
		chk_buff(flags, ft_strlen(str), 0, 0);
		i = -1;
		if (flags->X)
			while (str[++i])
				str[i] = ft_toupper(str[i]);
		ft_putstr(str);
	}
}

static void	print_num(const char *arg, t_flag *flags)
{
	int		i;
	long	l;

	i = (int)arg;
	l = (long)arg;
	if (flags->D || (flags->l && (flags->d || flags->i)))
	{
		chk_buff(flags, ft_nbrlen((long)arg), &l, 0);
		ft_putlong(l);
	}
	else if (flags->i || flags->d)
	{
		chk_buff(flags, ft_nbrlen((long)arg), (long*)&i, 0);
		ft_putnbr(i);
	}
	else if (flags->U || (flags->l && flags->u))
	{
		chk_buff(flags, ft_unbrlen((long)arg), &l, 0);
		ft_putulong((long)arg);
	}
	else if (flags->u)
	{
		chk_buff(flags, ft_unbrlen((int)arg), (long*)&i, 1);
		ft_putunbr((int)arg);
	}
	else if (flags->o || flags->O || flags->x || flags->X)
		ox_handler(arg, flags);
}

void		print_args(const char *arg, t_flag *flags)
{
	if (flags->c && !flags->l)
		ft_putstr((char *)&arg);
	else if (flags->s && !flags->l)
		ft_putstr(arg);
	else if (flags->d || flags->D || flags->i || flags->u || flags->U ||
			flags->o || flags->O || flags->x || flags->X)
		print_num(arg, flags);
	else
		flags->arg = 0;
	if (flags->left && flags->buff > 0)
		print_buff(flags);
}
