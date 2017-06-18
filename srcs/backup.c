/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <jwebb@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 02:43:26 by jwebb             #+#    #+#             */
/*   Updated: 2017/06/14 21:37:51 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * Return value: Number of characters printed or negative value on error
*/

static int		is_arg(const char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i' ||
			c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X'
			|| c == 'c' || c == 'C' || c == 'l' || c == 'h' || c == 'j'
			|| c == 'z' || c == '#' || c == ' ' || c == '+' || c == '-'
			|| c == '.' || (c >= '0' && c <= '9') || c == '%')
		return (1);
	return (0);
}

//c C d D h hh i j l ll o O p s S u U x X z # 0 + -
//a A e E f F g G L n $ * '

static int		chk_args(const char *str)
{
	int i;
	int args;

	i = -1;
	args = 0;
	while (str[++i])
	{
		while (str[i] == '%' && str[i + 1] == '%')
			i += 2;
		if (str[i] == '%')
			args += is_arg(str[i + 1]);
	}
	return (args);
}

int			ft_printf(const char *str, ...)
{
	t_flag		flags;
	t_va		va;
	int			i;
	int			len;
	static int	x = 0;
	
	++x;
	ft_memset(&flags, 0, sizeof(flags));
	ft_memset(&va, 0, sizeof(va));
	va.args = chk_args(str);
	va_start(va.ap, str);
	len = ft_strlen(str);
	i = 0;
	va.arg = va_arg(va.ap, char *);
	flags.ret = 0;
	while (i < len)
	{
		if (++x > len * len * len * len && x > 10)
			break ;
		if (str[i] == '%')
		{
			if (str[i] == '%' && !flags.arg)
			{
				++i;
				flags.arg = 1;
			}
//			if (str[i] == '%' && flags.arg)
//			{
//				ft_putchar('%');
//				++flags.ret;
//				++i;
//				flags.arg = 0;
//			}
		}
		if (flags.arg && is_arg(str[i]))
		{
			i += set_args(&flags, &str[i]);
			print_args(va.arg, &flags);
			if (flags.arg || str[i] == '%')
			{
				if (str[i] == '%')
				{
					ft_putchar('%');
					++flags.ret;
					++i;
					flags.arg = 0;
				}
				else
				{
					va.arg = va_arg(va.ap, char *);
					ft_memset(&flags, 0, sizeof(flags));
				}
			}
			else
				flags.arg = 1;
		}
		if (!flags.arg && str[i] != '%' && str[i])
		{
			ft_putchar(str[i++]);
			++flags.ret;
		}
	}
	va_end(va.ap);
	return (flags.ret);
}