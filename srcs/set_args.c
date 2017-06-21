/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <jwebb@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 02:56:30 by jwebb             #+#    #+#             */
/*   Updated: 2017/06/17 23:55:49 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	set_num_mods(t_flag *flags, const char *str, int ret)
{
	while (*str == '#' || *str == '0' || *str == '+' || *str == '-' ||
			*str == ' ')
	{
		if (*str == '#')
			flags->hash = 1;
		if (*str == '0')
			flags->zero = 1;
		if (*str == '+')
			flags->sign = 1;
		if (*str == '-')
			flags->left = 1;
		if (*str == ' ')
			flags->space = 1;
		++str;
		++ret;
	}
	while (*str >= '0' && *str <= '9')
	{
		flags->buff *= 10;
		flags->buff += *(str++) - '0';
		++ret;
	}
	return (ret);
}

static int	set_size_mods(t_flag *flags, const char *str, int ret)
{
	if (*str == 'h' && *(str + 1) == 'h')
	{
		flags->hh = 1;
		++ret;
	}
	else if (*str == 'h')
		flags->h = 1;
	if (*str == 'j')
		flags->j = 1;
	if (*str == 'l' && *(str + 1) == 'l')
	{
		flags->ll = 1;
		++ret;
	}
	else if (*str == 'l')
		flags->l = 1;
	if (*str == 'z')
		flags->z = 1;
	if (*str == 'h' || *str == 'j' || *str == 'l' || *str == 'z')
		++ret;
	return (ret);
}

static int	set_mods(t_flag *flags, const char *str, int ret)
{
	if (*str == '#' || *str == '+' || *str == '-' || *str == ' '
			|| (*str >= '0' && *str <= '9'))
	{
		ret += set_num_mods(flags, str, 0);
		str += ret;
	}
	if (*str == '.')
	{
		flags->dot = 1;
		ret++;
		if (ft_isdigit(*(str + 1)))
		{
			flags->prec = ft_atoi(str + 1);
			ret += ft_nbrlen(flags->prec);
		}
		else
			flags->prec = 0;
	}
	return (set_size_mods(flags, str, ret));
}

static int	set_num_args(t_flag *flags, const char *str)
{
	if (*str == 'd')
		flags->d = 1;
	else if (*str == 'D')
		flags->D = 1;
	else if (*str == 'i')
		flags->i = 1;
	else if (*str == 'o')
		flags->o = 1;
	else if (*str == 'O')
		flags->O = 1;
	else if (*str == 'p')
		flags->p = 1;
	else if (*str == 'u')
		flags->u = 1;
	else if (*str == 'U')
		flags->U = 1;
	else if (*str == 'x')
		flags->x = 1;
	else if (*str == 'X')
		flags->X = 1;
	return (1);
}

int			set_args(t_flag *flags, const char *str)
{
	int i;

	i = set_mods(flags, str, 0);
	if (!is_arg(str[i]))
			ft_putchar(str[i++]);
	else if (str[i] == 'd' || str[i] == 'D' || str[i] == 'i' || str[i] == 'o' ||
			str[i] == 'O' || str[i] == 'p' || str[i] == 'u' || str[i] == 'U' ||
			str[i] == 'x' || str[i] == 'X' || (str[i] >= '0' && str[i] <= '9'))
		i += set_num_args(flags, &str[i]);
	else if (str[i] == 'c' || str[i] == 'C')
		flags->c = 1;
	else if (str[i] == 's')
		flags->s = 1;
	else if (str[i] == 'S')
		flags->S = 1;
	else if (str[i] == '%')
		flags->pcent = 1;
	if (flags->c || flags->s || flags->S || flags->pcent || flags->r)
		++i;
	return (i);
}
