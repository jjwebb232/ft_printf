/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <jwebb@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 11:23:33 by jwebb             #+#    #+#             */
/*   Updated: 2017/06/21 17:33:50 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_text(char **str, const void *arg, t_flag *flags)
{
	if (flags->c)
		ft_addchar(str, (char)arg);
	else if ((flags->l && flags->s) || flags->ls)
		ft_addwstr(str, (wchar_t *)arg);
	else if (!arg)
		ft_addstr(str, "(null)");
	else
		ft_addstr(str, (char *)arg);
}

void	get_uo(char **str, const void *arg, t_flag *flags)
{
	int base;

	if (flags->o || flags->lo)
		base = 8;
	else
		base = 10;
	if (flags->u && flags->ll)
		*str = ft_ultoa_base((unsigned long long)arg, base);
	else if (flags->l || flags->lo || flags->lu)
		*str = ft_ultoa_base((unsigned long)arg, base);
	else if (flags->hh)
		*str = ft_ultoa_base((unsigned char)arg, base);
	else if (flags->h)
		*str = ft_ultoa_base((unsigned short)arg, base);
	else if (flags->u && flags->j)
		*str = ft_ultoa_base((intmax_t)arg, base);
	else if (flags->u && flags->z)
		*str = ft_ultoa_base((ssize_t)arg, base);
	else
		*str = ft_ultoa_base((unsigned int)arg, base);
}

void	get_special_nums(char **str, const void *arg, t_flag *flags)
{
	ft_memdel((void**)str);
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

void	get_nums(char **str, const void *arg, t_flag *flags)
{
	ft_memdel((void**)str);
	if (flags->u || flags->o || flags->lu || flags->lo)
		get_uo(str, arg, flags);
	else if ((flags->i || flags->d) && flags->ll)
		*str = ft_ltoa((int64_t)arg);
	else if (((flags->i || flags->d) && flags->l) || flags->ld)
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
