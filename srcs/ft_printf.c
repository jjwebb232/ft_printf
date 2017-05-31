/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <jwebb@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 02:43:26 by jwebb             #+#    #+#             */
/*   Updated: 2017/05/31 08:08:18 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * Return value: Number of characters printed or negative value on error
*/

static int		is_arg(const char c)
{
	if (c == 's' || c == 'S' || c == 'd' || c == 'D' || c == 'i' //||
//			c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X'
//			|| c == 'c' || c == 'C' || c == 'l' || c == 'h'
//			|| c == '#' || c == '+' || c == '-'
)//			|| (c >= '0' && c <= '9'))
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
//	int			space_count;
	
	++x;
	ft_memset(&flags, 0, sizeof(flags));
	ft_memset(&va, 0, sizeof(va));
	va.args = chk_args(str);
	va_start(va.ap, str);
	len = ft_strlen(str);
	i = 0;
	va.arg = va_arg(va.ap, char *);
//	space_count = 1;
	while (i < len)
	{
		if (str[i] == '%')
		{
			if (str[i] == '%' && !flags.arg)
			{
				++i;
				flags.arg = 1;
			}
			if (str[i] == '%' && flags.arg)
			{
//				space_count = 1;
				ft_putchar('%');
				++i;
				flags.arg = 0;
			}
		}
		if (flags.arg && is_arg(str[i]))
		{
//			if (str[i] == ' ')
//				printf("test\n");
//			while (--space_count)
//				ft_putchar(' ');
//			space_count = 1;
			i += set_args(&flags, &str[i]);
//			printf("char: %c\n", str[i]);
			print_args(va.arg, &flags);
//			i += print_arg(&str[i], va.arg, &flags);
			if (flags.arg)
			{
				va.arg = va_arg(va.ap, char *);
				ft_memset(&flags, 0, sizeof(flags));
			}
			else
				flags.arg = 1;
		}
//		if (flags.arg && str[i] == ' ')
//			++space_count;
//		else
		if (!flags.arg && str[i] != '%')
			ft_putchar(str[i++]);
	}
	va_end(va.ap);
	return (0);
}
