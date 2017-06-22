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

char			*add_neg(char *new)
{
	char	*neg;

	neg = ft_memalloc(ft_strlen(new) + 1);
	neg[0] = '-';
	neg = ft_strcat(neg, new);
	ft_memdel((void**)&new);
	new = (char*)ft_memalloc(ft_strlen(neg));
	new = ft_strcpy(new, neg);
	ft_memdel((void**)&neg);
	return (new);
}

char			*build_new(char *str, char **new, int len)
{
	*new = (char*)ft_memalloc(ft_strlen(str) + len);
	*new = ft_strcpy(*new, str);
	return (*new);
}

unsigned int	add_chars(char **str, char c, int len, t_flag *flags)
{
	char	*new;
	char	*tmp;

	new = build_new(*str, &new, len);
	tmp = fill_tmp(len, c);
	if (new[0] == '-' && flags && (flags->zero || flags->prec))
		new = ft_strcpy(new, &new[1]);
	if (!flags || !flags->left)
	{
		tmp = ft_realloc(tmp, ft_strlen(tmp) + ft_strlen(new));
		tmp = ft_strcat(tmp, new);
		ft_memdel((void**)&new);
		new = (char*)ft_memalloc(ft_strlen(tmp));
		new = ft_strcpy(new, tmp);
	}
	else
		new = ft_strcat(new, tmp);
	if (*str[0] == '-' && flags && (flags->zero || flags->prec))
		new = add_neg(new);
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
/*
void	num_precision(char **str, t_flag *flags, unsigned int len)
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

void	add_precision(char **str, t_flag *flags, unsigned int len, char c)
{
	if (flags->buff > flags->prec && !(flags->buff == flags->prec + 1 &&
		NUM_FLAGS && *str[0] == '-'))
		c = ' ';
	if ((flags->s || flags->ls) && len > flags->prec)
		*str = (char*)ft_realloc(*str, flags->prec);
	if ((NUM_FLAGS || flags->x || flags->xx || flags->o || flags->lo))
		num_precision(str, flags, len);
	if (!flags->prec && ((flags->s || flags->ls || flags->x || flags->xx) ||
			(flags->o && !flags->hash && !ft_strcmp(*str, "0"))))
		*str = new_str();
	len = ft_strlen(*str);
	if (flags->buff && flags->sign && ft_isdigit(*str[0]) && c == ' ' &&
			!flags->u && !flags->lu)
		add_chars(str, '+', 1, NULL);
	if (flags->buff > len)
		if (!((flags->u || flags->lu) && c == ' '))
			add_chars(str, c,
				flags->buff - flags->sign - flags->space - len, flags);
}

void	init_mods(char **str, t_flag *flags, char *c, unsigned int *len)
{
	*len = ft_strlen(*str);
	*c = ' ';
	if ((flags->zero && !flags->left) || (flags->o && flags->dot &&
			flags->buff < flags->prec))
		*c = '0';
	if ((flags->x || flags->xx) && flags->hash && ft_strcmp(*str, "0"))
		*len += 2;
	if ((flags->x || flags->xx) && flags->hash && ft_strcmp(*str, "0")
			&& !flags->zero)
		add_xprefix(str);
	if (flags->o && flags->hash && ft_strcmp(*str, "0"))
		*len += add_chars(str, '0', 1, NULL);
	if (flags->zero && flags->sign && *str[0] != '-')
		++*len;
}

void	apply_mods(char **str, t_flag *flags, const void *arg)
{
	unsigned int	len;
	int				i;
	char			c;

	init_mods(str, flags, &c, &len);
	if (flags->dot)
		add_precision(str, flags, len, c);
	else if (flags->buff > len)
	{
		if (flags->c && !arg)
			i = 1;
		else
			i = flags->buff - flags->pcent;
		add_chars(str, c, i - len, flags);
	}
	if ((flags->x || flags->xx) && flags->hash && ft_strcmp(*str, "0")
			&& flags->zero && *str[0])
		add_xprefix(str);
	if (flags->sign && NUM_FLAGS && !flags->u && !flags->lu &&
			ft_isdigit(*str[0]))
		add_chars(str, '+', 1, NULL);
	else if (flags->space && NUM_FLAGS && !flags->u && !flags->lu &&
			*str[0] != '-' && (!flags->buff || flags->dot))
		add_chars(str, ' ', 1, NULL);
}*/
