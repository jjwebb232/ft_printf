/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmethod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <jwebb@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 21:39:06 by jwebb             #+#    #+#             */
/*   Updated: 2017/06/15 05:34:48 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ltoa(long long nbr);

void	get_text(char **str, const void *arg, t_flag *flags)
{
	if (flags->c)
		ft_addchar(str, (char)arg);
	else if (flags->pcent)
		ft_addchar(str, '%');
	else if ((flags->l && flags->s) || flags->S)
		ft_addwstr(str, (wchar_t *)arg);
	else
		ft_addstr(str, (char *)arg);
}

void	get_nums(char **str, const void *arg, t_flag *flags)
{
	if ((flags->o && flags->l) || flags->O)
		*str = ft_ultoa_base((long)arg, 8);
	else if (flags->o && flags->hh)
		*str = ft_uctoa_base((long)arg, 8);
	else if (flags->o && flags->h)
		*str = ft_ustoa_base((long)arg, 8);
	else if (flags->o)
		*str = ft_uitoa_base((long)arg, 8);
	else if ((flags->i || flags->d) && flags->ll)
		*str = ft_ltoa((int64_t)arg);
	else if (((flags->i || flags->d) && flags->l) || flags->D)
		*str = ft_ltoa((long)arg);
	else if ((flags->i || flags->d) && flags->h)
		*str = ft_ltoa((short)arg);
	else if ((flags->i || flags->d) && flags->hh)
		*str = ft_ltoa((char)arg);
	else if (flags->i || flags->d)
		*str = ft_ltoa((int)arg);
}

void	get_special_nums(char **str, const void *arg, t_flag *flags)
{
	char	*tmp;

	*str = ft_ultoa_base((unsigned int)arg, 16);
	if (!flags->p)
		return ;
	tmp = (char*)ft_memalloc(2);
	tmp = ft_strcat(tmp, "0x");
	*str = ft_strcat(tmp, *str);
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

void	add_chars(char **str, char c, int len, int left)
{
	char	*tmp;

	tmp = fill_tmp(len, c);
	if (left)
		*str = ft_strcat(*str, tmp);
	else
		*str = ft_strcat(tmp, *str);
}

void	apply_mods(char **str, t_flag *flags)
{
	char	*tmp;
	unsigned int		len;
	int		i;
	char	c;

	len = ft_strlen(*str);
	i = 0;
	c = '0';
	tmp = (char*)ft_memalloc(1);
	if (flags->sign && NUM_FLAGS && *str[0] != '-')
		add_chars(str, '+', 1, 0);
	else if (flags->space && NUM_FLAGS && *str[0] != '-')
		add_chars(str, ' ', 1, 0);
	if (flags->dot)
	{
		if ((flags->s || flags->S) && ft_strlen(*str) > flags->prec)
			*str = (char*)ft_realloc(*str, flags->prec);
		if ((NUM_FLAGS || flags->x || flags->X || flags->o || flags->O)
				&& len < flags->prec)
			add_chars(str, c, flags->prec - len, 0);
		if (flags->buff && flags->buff > (int)flags->prec &&
				flags->buff - (int)flags->prec > (int)len)
			add_chars(str, c, flags->buff - flags->prec - len, 0);
		if (flags->buff && flags->buff < (int)flags->prec &&
				(int)flags->prec - flags->buff > (int)len)
			add_chars(str, c, flags->prec - flags->buff - len, 0);
	}
	else if (flags->buff > (int)len)
	{
		if (!flags->zero || flags->left)
			c = ' ';
		add_chars(str, c, flags->buff - len, flags->left);
	}
}

int		ft_strmethod(const void *arg, t_flag *flags)
{
	char	*str;
	unsigned int		len;
	int		i;

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
				flags->dot || flags->buff)
			apply_mods(&str, flags);
		i = -1;
		if (flags->X)
			while (str[++i])
				str[i] = ft_toupper(str[i]);
		ft_putstr(str);
		len = ft_strlen(str);
//		ft_memdel((void**)&str);
	}
	flags->ret += len;
	return (len);
}
