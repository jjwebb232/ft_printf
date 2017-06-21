/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmethod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <jwebb@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 21:39:06 by jwebb             #+#    #+#             */
/*   Updated: 2017/06/20 12:00:50 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_text(char **str, const void *arg, t_flag *flags)
{
	if (flags->c)
		ft_addchar(str, (char)arg);
	else if (flags->pcent)
		ft_addchar(str, '%');
	else if ((flags->l && flags->s) || flags->S)
		ft_addwstr(str, (wchar_t *)arg);
	else if (!arg)
		ft_addstr(str, "(null)");
	else
		ft_addstr(str, (char *)arg);
}

void	get_nums(char **str, const void *arg, t_flag *flags)
{
	int base;

	if (flags->o || flags->O)
		base = 8;
	else
		base = 10;
	if (flags->u && flags->ll)
		*str = ft_ultoa_base((long long)arg, base);
	else if (((flags->o || flags->u) && flags->l) || flags->O || flags->U)
		*str = ft_ultoa_base((long)arg, base);
	else if ((flags->o || flags->u) && flags->hh)
		*str = ft_uctoa_base((char)arg, base);
	else if ((flags->o || flags->u) && flags->h)
		*str = ft_ustoa_base((short)arg, base);
	else if (flags->u && flags->j)
		*str = ft_ultoa_base((intmax_t)arg, base);
	else if (flags->u && flags->z)
		*str = ft_ultoa_base((ssize_t)arg, base);
	else if (flags->o || flags->u)
		*str = ft_uitoa_base((long)arg, base);
	else if ((flags->i || flags->d) && flags->ll)
		*str = ft_ltoa((int64_t)arg);
	else if (((flags->i || flags->d) && flags->l) || flags->D)
		*str = ft_ltoa((long)arg);
	else if ((flags->i || flags->d) && flags->h)
		*str = ft_ltoa((short)arg);
	else if ((flags->i || flags->d) && flags->hh)
		*str = ft_ltoa((char)arg);
	else if ((flags->i || flags->d) && flags->j)
		*str = ft_ltoa((intmax_t)arg);
	else if ((flags->i || flags->d) && flags->z)
		*str = ft_ltoa((ssize_t)arg);
	else if (flags->i || flags->d)
		*str = ft_ltoa((int)arg);
}

int		add_xprefix(char **str)
{
	char	*tmp;

	tmp = (char*)ft_memalloc(2);
	tmp = ft_strcat(tmp, "0x");
	*str = ft_strcat(tmp, *str);
	return (2);
}

void	get_special_nums(char **str, const void *arg, t_flag *flags)
{
	if (!flags->p)
	{
		if (flags->ll)
			*str = ft_ultoa_base((unsigned long long)arg, 16);
		else if (flags->l)
			*str = ft_ultoa_base((unsigned long)arg, 16);
		else if (flags->j)
			*str = ft_ultoa_base((intmax_t)arg, 16);
		else if (flags->z)
			*str = ft_ultoa_base((ssize_t)arg, 16);
		else
			*str = ft_ultoa_base((unsigned int)arg, 16);
	}
	else
	{
		*str = ft_ultoa_base((unsigned long)arg, 16);
		add_xprefix(str);
	}
}

char	*fill_tmp(int len, char c)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = (char*)ft_memalloc(len);
	while (i < len)
		tmp[i++] = c;
	tmp[i] = '\0';
	return (tmp);
}

unsigned int	add_chars(char **str, char c, int len, t_flag *flags)
{
	char	*new;
	char	*tmp;
	char	*neg;
	int		i;

//	ft_putstr("adding chars\n");
//	new = *str;
	new = (char*)ft_memalloc(ft_strlen(*str) + len);
	new = ft_strcpy(new, *str);
	tmp = fill_tmp(len, c);
	i = 0;
	if (new[i] == '-' && flags && (flags->zero || flags->prec))
		new = ft_strcpy(new, &new[1]);
	if (!flags || !flags->left)
	{
		tmp = ft_strcat(tmp, &new[i]);
		ft_memdel((void**)&new);
		new = (char*)ft_memalloc(ft_strlen(tmp));
		new = ft_strcpy(new, tmp);
	}
	else
		new = ft_strcat(&new[i], tmp);
	if (*str[0] == '-' && flags && (flags->zero || flags->prec))
	{
		neg = ft_memalloc(1);
		neg[0] = '-';
//		ft_memdel((void**)&tmp);
		neg = ft_strcat(neg, new);
		ft_memdel((void**)&new);
		new = (char*)ft_memalloc(ft_strlen(neg));
		new = ft_strcpy(new, neg);
		ft_memdel((void**)&neg);
	}
//	else
//		*str = ft_strcat(neg, new);
//	ft_putstr("modded:\t|");
//	ft_putstr(new);
//	ft_putstr("|\n");
	ft_memdel((void**)str);
	*str = ft_memalloc(ft_strlen(new));
	*str = ft_strcpy(*str, new);
	ft_memdel((void**)&new);
	ft_memdel((void**)&tmp);
	return (len);
}

char	*new_str(void)
{
	char	*str;

	str = ft_memalloc(1);
	str[0] = '\0';
	return (str);
}

void	apply_mods(char **str, t_flag *flags, const void *arg)
{
	char	*tmp;
	unsigned int		len;
	int		i;
	char	c;

	len = ft_strlen(*str);
	tmp = (char*)ft_memalloc(1);
	c = ' ';
	if ((flags->zero && !flags->left) || (flags->o && flags->dot &&
			flags->buff < flags->prec))
		c = '0';
	if ((flags->x || flags->X) && flags->hash && ft_strcmp(*str, "0"))
		len += 2;
	if ((flags->x || flags->X) && flags->hash && ft_strcmp(*str, "0")
			&& !flags->zero)
		add_xprefix(str);
	if (flags->o && flags->hash && ft_strcmp(*str, "0"))
		len += add_chars(str, '0', 1, NULL);
	if (flags->zero && flags->sign && *str[0] != '-')
		++len;
	if (flags->dot)
	{
		if ((flags->s || flags->S) && len > flags->prec)
			*str = (char*)ft_realloc(*str, flags->prec);
		if ((NUM_FLAGS || flags->x || flags->X || flags->o || flags->O))
		{
			if (*str[0] == '-' && len < flags->prec)
				add_chars(str, '0', flags->prec - len + 1, flags);
			else if (len < flags->prec)
				add_chars(str, '0', flags->prec - len, NULL);
			else if (!ft_strcmp(*str, "0") && !flags->hash)
			{
				*str = ft_memalloc(1);
				*str[0] = '\0';
			}
		}
		if (!flags->prec && ((flags->s || flags->S || flags->x || flags->X) ||
				(flags->o && !flags->hash && !ft_strcmp(*str, "0"))))
			*str = new_str();
		len = ft_strlen(*str);
		i = (int)c;
		if (flags->buff > flags->prec &&
				!(flags->buff == flags->prec + 1 &&
				NUM_FLAGS && *str[0] == '-'))
			i = ' ';
		if (flags->buff && flags->sign && ft_isdigit(*str[0]) && i == ' ' &&
				!flags->u && !flags->U)
			add_chars(str, '+', 1, NULL);
		if (flags->buff > len)
			if (!((flags->u || flags->U) && i == ' '))
			add_chars(str, (char)i,
					flags->buff - flags->sign - flags->space - len, flags);
	}
	else if (flags->buff > len)
	{
		if (flags->c && !arg)
			i = 1;
		else
			i = flags->buff;
		add_chars(str, c, i - len, flags);
	}
	if ((flags->x || flags->X) && flags->hash && ft_strcmp(*str, "0")
			&& flags->zero && *str[0])
			add_xprefix(str);
	if (flags->sign && NUM_FLAGS && !flags->u && !flags->U &&
			ft_isdigit(*str[0]))
		add_chars(str, '+', 1, NULL);
	else if (flags->space && NUM_FLAGS && !flags->u && !flags->U &&
			*str[0] != '-' && (!flags->buff || flags->dot))
		add_chars(str, ' ', 1, NULL);
}

int		print_r(const void *arg)
{
	char			*style;
	int				len;

	style = (char*)ft_memalloc(4 + ft_strlen(arg));
	style = ft_strcat(style, A_START);
	style = ft_strcat(style, arg);
	style = ft_strcat(style, A_END);
	ft_putstr(style);
	len = ft_strlen(style);
	ft_memdel((void**)&style);
	return (len);
}

void	ft_buildstr(const void *arg, t_flag *flags, char **str)
{
	*str = (char*)ft_memalloc(1);
	if (flags->c || flags->s || flags->ls || flags->pcent)
		get_text(str, arg, flags);
	else if (NUM_FLAGS || flags->o || flags->lo)
		get_nums(str, arg, flags);
	else if (flags->x || flags->xx || flags->p)
		get_special_nums(str, arg, flags);
}

int		ft_printstr(const void *arg, t_flag *flags, char *str)
{
	int				i;
	int				len;

	if (flags->hash || flags->zero || flags->left || flags->space ||
			flags->dot || flags->buff || flags->sign)
		apply_mods(&str, flags, arg);
	i = -1;
	if (flags->xx)
		while (str[++i])
			if (ft_isalpha(str[i]))
				str[i] = ft_toupper(str[i]);
	ft_putstr(str);
	if (flags->c && !arg)
		ft_putchar(0);
	len = ft_strlen(str);
	ft_memdel((void**)&str);
	return (len);
}

int		ft_strmethod(const void *arg, t_flag *flags)
{
	char			*str;
	unsigned int	len;

	if (flags->r)
		return (flags->ret += print_r(arg));
	ft_buildstr(arg, flags, &str);
	len = 0;
	if (str)
		len = ft_printstr(arg, flags, str);
	if (flags->c && !len && !flags->buff)
		len = 1;
	else if (flags->c && flags->buff)
		len = flags->buff;
	flags->ret += len;
	return (len);
}

/*
int		ft_strmethod(const void *arg, t_flag *flags)
{
	char			*str;
	unsigned int	len;
	int				i;

	str = (char*)ft_memalloc(1);
	len = 0;
	if (flags->c || flags->s || flags->S || flags->pcent)
		get_text(&str, arg, flags);
	else if (NUM_FLAGS || flags->o || flags->O)
		get_nums(&str, arg, flags);
	else if (flags->x || flags->X || flags->p)
		get_special_nums(&str, arg, flags);
	if (str)
	{
		if (flags->hash || flags->zero || flags->left || flags->space ||
				flags->dot || flags->buff || flags->sign)
			apply_mods(&str, flags, arg);
		i = -1;
		if (flags->X)
			while (str[++i])
				if (ft_isalpha(str[i]))
					str[i] = ft_toupper(str[i]);
		ft_putstr(str);
		if (flags->c && !arg)
			ft_putchar(0);
		len = ft_strlen(str);
	}
	if (flags->c && !len && !flags->buff)
		len = 1;
	else if (flags->c && flags->buff)
		len = flags->buff;
	flags->ret += len;
	return (len);
}*/
