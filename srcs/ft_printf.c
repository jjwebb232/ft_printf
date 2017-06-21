/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <jwebb@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 02:43:26 by jwebb             #+#    #+#             */
/*   Updated: 2017/06/21 13:37:36 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			is_arg(const char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i' ||
			c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X'
			|| c == 'c' || c == 'C' || c == 'l' || c == 'h' || c == 'j'
			|| c == 'z' || c == '#' || c == ' ' || c == '+' || c == '-'
			|| c == '.' || (c >= '0' && c <= '9') || c == '%' || c == 'r')
		return (1);
	return (0);
}

static int	init_printf(t_flag *flags, t_va *va, int *i, const char *str)
{
	if (!str)
		return (-1);
	ft_memset(flags, 0, sizeof(*flags));
	ft_memset(va, 0, sizeof(*va));
	*i = 0;
	return (ft_strlen(str));
}

static int	print_args(t_flag *flags, t_va *va, int *i, const char *str)
{
	*i += set_args(flags, &str[*i]);
	if (flags.ld)
		ft_putchar('A');
	else
		ft_printf_arg(va->arg, flags);
	if (!flags->pcent)
		va->arg = va_arg(va->ap, char*);
	return (flags->ret);
}

static void	chk_arg(t_flag *flags, int *i, const char *str)
{
	if (str[*i] == '%')
	{
		if (str[*i] == '%' && !flags->arg)
		{
			++*i;
			flags->arg = 1;
		}
		if (!is_arg(str[*i]))
			flags->arg = 0;
	}
}

int			ft_printf(const char *str, ...)
{
	t_flag		flags;
	t_va		va;
	int			i;
	int			len;
	int			ret;

	if ((len = init_printf(&flags, &va, &i, str)) == -1)
		return (0);
	va_start(va.ap, str);
	va.arg = va_arg(va.ap, char *);
	ret = 0;
	while (i < len)
	{
		chk_arg(&flags, &i, str);
		if (flags.arg && is_arg(str[i]))
			ret += print_args(&flags, &va, &i, str);
		else if (!flags.arg && str[i] != '%' && str[i])
		{
			ft_putchar(str[i++]);
			++ret;
		}
		ft_memset(&flags, 0, sizeof(flags));
	}
	va_end(va.ap);
	return (ret);
}
