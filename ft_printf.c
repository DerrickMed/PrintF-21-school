/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srorscha <srorscha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 21:36:02 by srorscha          #+#    #+#             */
/*   Updated: 2020/12/20 23:44:00 by srorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t g_len;

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	g_len++;
}

void	print_arg(t_data *flags, va_list *args)
{
	flags->nextpls = 1;
	if (flags->conver == 'c')
		print_char(flags, args);
	else if (flags->conver == 's')
		print_string(flags, args);
	else if (flags->conver == 'd' || flags->conver == 'i')
		print_int(flags, args);
	else if (flags->conver == 'X')
		print_x(flags, args, 0);
	else if (flags->conver == 'x')
		print_x(flags, args, 1);
	else if (flags->conver == 'u')
		print_uint(flags, args);
	else if (flags->conver == 'p')
		print_pointer(flags, args);
	else if (flags->conver == '%')
		print_percent(flags);
}

void	check_flags(t_data *flags, const char *print, va_list *args)
{
	if (*print == '0' && !(flags->width_enable) && !(flags->prec_enable))
		flags->isnull = 1;
	else if (*print == '-' && !(flags->width_enable) && !(flags->prec_enable))
		flags->minus = 1;
	else if (*print == '.')
		flags->was_dot = 1;
	else if (*print == '*' || ft_strchr(DIGITS, (char)*print))
		parse_width_prec(print, flags, args);
	else if (ft_strchr(CONVERS, (char)*print))
		flags->conver = *print;
	else
		flags->nextpls = 1;
	if (flags->conver)
		print_arg(flags, args);
}

void	ft_parser(const char *print, va_list *args)
{
	t_data flags;

	while (*print)
	{
		clear_flags(&flags);
		if (*print == '%')
		{
			clear_flags(&flags);
			while (*(print) && !(flags.nextpls))
			{
				check_flags(&flags, ++print, args);
				if (flags.nextpls && !flags.conver)
					break ;
				if (flags.nextpls)
					print++;
			}
		}
		else if (*print == '%' && *(print - 1) != '%')
			print++;
		if (!(flags.nextpls))
		{
			ft_putchar_fd(*print, 1);
			print++;
		}
	}
}

int		ft_printf(const char *to_print, ...)
{
	va_list args;

	g_len = 0;
	if (!to_print)
		return (-1);
	va_start(args, to_print);
	ft_parser(to_print, &args);
	va_end(args);
	return (g_len);
}

