/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <jwebb@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 03:11:05 by jwebb             #+#    #+#             */
/*   Updated: 2017/05/31 11:54:13 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_buff(t_flag *flags)
{
	char	c;

	c = ' ';
	if (flags->zero && !flags->left)
		c = '0';
	while (flags->buff-- > 0)
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
	if (flags->zero && !flags->left)
	{
		if (i && (int)*n < 0)
			*n = (int)*n * -1;
		if (n < 0)
			*n *= -1;
		if (s == -1)
			ft_putchar('-');
		if (s == 1 && ((i && (int)*n >= 0) || (!i && n < 0)))
			ft_putchar('+');
	}
	if (s)
		--flags->buff;
	flags->buff -= offset;
	if (!flags->left && flags->buff > 0)
		print_buff(flags);
	if (s == 1 && !flags->zero && ((i && (int)*n >= 0) || (!i && n < 0)))
		ft_putchar('+');
}

static void	ox_handler(const void *arg, t_flag *flags)
{
	char	*str;
	int		i;

	if (flags->o || flags->O)
	{
		if (flags->O || (flags->l && flags->o))
			str = ft_ultoa_base((long)arg, 8);
		else if (flags->o && flags->hh)
			str = ft_uctoa_base((long)arg, 8);
		else if (flags->o && flags->h)
			str = ft_ustoa_base((long)arg, 8);
		else
			str = ft_uitoa_base((long)arg, 8);
		chk_buff(flags, ft_strlen(str), 0, 0);
		if (flags->hash && (ft_strlen(str) > 1 || str[0] != '0'))
			ft_putnbr(0);
		ft_putstr(str);
	}
	else if ((flags->x || flags->X) && !flags->l)
	{
		str = ft_itoh((unsigned int)arg);
		if (flags->hh)
			str += 4;
		else if (flags->h)
			str += 2;
		chk_buff(flags, ft_strlen(str), 0, 0);
		if (flags->hash)
			flags->buff -= 2;
		if (flags->hash && flags->x && str[0])
			ft_putstr("0x");
		if (flags->hash && flags->X && str[0])
			ft_putstr("0X");
		if (flags->hash && (flags->x || flags->X) && !str[0])
			ft_putchar('0');
		i = -1;
		if (flags->X)
			while (str[++i])
				if (ft_isalpha(str[i]))
					str[i] = ft_toupper(str[i]);
		ft_putstr(str);
	}
	else if (flags->x || flags->X || flags->p)
	{
		if (flags->hash || flags->p)
			flags->buff -=2;
		if ((flags->hash && flags->x) || flags->p)
			ft_putstr("0x");
		if (flags->hash && flags->X)
			ft_putstr("0X");
		str = ft_ultoa_base((unsigned long)arg, 16);
		chk_buff(flags, ft_strlen(str), 0, 0);
		i = -1;
		if (flags->X)
			while (str[++i])
				str[i] = ft_toupper(str[i]);
		ft_putstr(str);
	}
}

static void	print_num(const void *arg, t_flag *flags)
{
	int		i;
	long	l;
	short	s;
	char	c;
	size_t	st;

	i = (int)arg;
	l = (long)arg;
	s = (short)arg;
	c = (char)arg;
	st = (size_t)arg;
	if (flags->D || (flags->l && (flags->d || flags->i)))
	{
		chk_buff(flags, ft_nbrlen((long)arg), &l, 0);
		ft_putlong((long)arg);
	}
	else if (flags->ll && (flags->i || flags->d))
	{
		chk_buff(flags, ft_nbrlen((long long)arg), &l, 0);
		ft_putlonglong((long long)arg);
	}
	else if (flags->hh && (flags->i || flags->d))
	{
		chk_buff(flags, ft_nbrlen((char)arg), (long*)&c, 1);
		ft_putascii((char)arg);
	}
	else if (flags->h && (flags->i || flags->d))
	{
		chk_buff(flags, ft_nbrlen((short)arg), (long*)&s, 1);
		ft_putshort((short)arg);
	}
	else if (flags->j && (flags->i || flags->d))
	{
		chk_buff(flags, ft_nbrlen((intmax_t)arg), &l, 0);
		ft_putintmax_t((intmax_t)arg);
	}
	else if (flags->z && (flags->i || flags->d))
	{
		chk_buff(flags, ft_nbrlen((long long)arg), &l, 0);
		ft_putlonglong((long long)arg);
	}
	else if (flags->i || flags->d)
	{
		chk_buff(flags, ft_nbrlen((int)arg), (long*)&i, 1);
		ft_putnbr((int)arg);
	}
	else if (flags->U || (flags->l && flags->u))
	{
		chk_buff(flags, ft_unbrlen((unsigned long)arg), &l, 0);
		ft_putulong((unsigned long)arg);
	}
	else if (flags->u && flags->ll)
	{
		chk_buff(flags, ft_unbrlen((unsigned long long)arg), &l, 0);
		ft_putulonglong((unsigned long long)arg);
	}
	else if (flags->u && flags->hh)
	{
		chk_buff(flags, ft_unbrlen((unsigned char)arg), (long*)&l, 1);
		ft_putunbr((unsigned char)arg);
	}
	else if (flags->u && flags->h)
	{
		chk_buff(flags, ft_unbrlen((unsigned short)arg), (long*)&l, 1);
		ft_putunbr((unsigned short)arg);
	}
	else if (flags->u && flags->j)
	{
		chk_buff(flags, ft_nbrlen((uintmax_t)arg), (long*)&l, 1);
		ft_putuintmax_t((uintmax_t)arg);
	}
	else if (flags->u && flags->z)
	{
		chk_buff(flags, ft_nbrlen((long long)arg), (long*)&l, 1);
		ft_putsize_t((size_t)arg);
	}
	else if (flags->u)
	{
		chk_buff(flags, ft_unbrlen((unsigned int)arg), (long*)&i, 1);
		ft_putunbr((unsigned int)arg);
	}
	else if (flags->o || flags->O || flags->x || flags->X || flags->p)
		ox_handler(arg, flags);
}

void		print_args(const void *arg, t_flag *flags)
{
	if (flags->c && !flags->l)
		ft_putstr((char *)&arg);
	else if (flags->c)
		ft_putwchar((wchar_t)arg);
	else if (flags->s && !flags->l)
		ft_putstr(arg);
	else if (flags->S || (flags->s && flags->l))
		ft_putwstr((wchar_t *)arg);
	else if (flags->d || flags->D || flags->i || flags->u || flags->U ||
			flags->o || flags->O || flags->x || flags->X || flags->p)
		print_num(arg, flags);
	else
		flags->arg = 0;
	if (flags->left && flags->buff > 0)
		print_buff(flags);
}
