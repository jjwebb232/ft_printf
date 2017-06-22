/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <jwebb@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 09:50:53 by jwebb             #+#    #+#             */
/*   Updated: 2017/06/21 13:14:58 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	*str = (char*)ft_memalloc(2);
	if (flags->c || flags->s || flags->ls)
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
	if (flags->pcent && flags->left)
		ft_putchar('%');
	ft_putstr(str);
	if (flags->pcent && !flags->left)
		ft_putchar('%');
	if (flags->c && !arg)
		ft_putchar(0);
	len = ft_strlen(str) + flags->pcent;
	ft_memdel((void**)&str);
	return (len);
}

int		ft_printf_arg(const void *arg, t_flag *flags)
{
	char			*str;
	unsigned int	len;

	if (flags->r)
		return (flags->ret += print_r(arg));
	len = 0;
	ft_buildstr(arg, flags, &str);
	if (str)
		len = ft_printstr(arg, flags, str);
	if (flags->c && !len && !flags->buff)
		len = 1;
	else if (flags->c && flags->buff)
		len = flags->buff;
	flags->ret += len;
	return (len);
}
