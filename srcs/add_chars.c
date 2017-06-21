/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_chars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <jwebb@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 11:22:11 by jwebb             #+#    #+#             */
/*   Updated: 2017/06/21 11:22:27 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*fill_tmp(int len, char c)
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
