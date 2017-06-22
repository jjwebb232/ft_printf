/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <jwebb@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 02:43:26 by jwebb             #+#    #+#             */
/*   Updated: 2017/06/21 20:17:09 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * Return value: Number of characters printed or negative value on error
*/

int				is_arg(const char c)
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
/*
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
	int			ret;
	int			x;

	if (!str)
		return (0);	
	ft_memset(&flags, 0, sizeof(flags));
	ft_memset(&va, 0, sizeof(va));
	va.args = chk_args(str);
	va_start(va.ap, str);
	len = ft_strlen(str);
	i = 0;
	va.arg = va_arg(va.ap, char *);
	ret = 0;
	x = 0;
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
			if (!is_arg(str[i]))
				flags.arg = 0;
		}
		if (flags.arg && is_arg(str[i]))
		{
			i += set_args(&flags, &str[i]);
			ft_strmethod(va.arg, &flags);
			ret += flags.ret;
			if (!flags.pcent)
				va.arg = va_arg(va.ap, char *);
			ft_memset(&flags, 0, sizeof(flags));
		}
		else if (flags.arg && str[i] && str[i + 1])
			flags.arg = 0;
		if (!flags.arg && str[i] != '%' && str[i])
		{
			ft_putchar(str[i++]);
			++ret;
		}
	}
	va_end(va.ap);
	return (ret);
}*/
