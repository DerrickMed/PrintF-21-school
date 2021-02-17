/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srorscha <srorscha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 21:35:53 by srorscha          #+#    #+#             */
/*   Updated: 2020/12/19 23:14:07 by srorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_width_prec(const char *print, t_data *flags, va_list *args)
{
	if (*print == '*' && !(flags->was_dot) && !(flags->width_enable))
	{
		flags->width = va_arg(*args, int);
		flags->width_enable = 1;
	}
	else if (*print == '*' && flags->was_dot && !(flags->prec_enable))
	{
		flags->prec = va_arg(*args, int);
		flags->prec_enable = 1;
	}
	else if (!(flags->was_dot) && !(flags->width_enable))
	{
		flags->width_enable = 1;
		flags->width = ft_atoi(print);
	}
	else if (flags->was_dot && !(flags->prec_enable))
	{
		flags->prec_enable = 1;
		flags->prec = ft_atoi(print);
	}
	flags->minus = (flags->width < 0) ? 1 : flags->minus;
	flags->width = (flags->width < 0) ? -flags->width : flags->width;
}

void	clear_flags(t_data *flags)
{
	flags->isnull = 0;
	flags->minus = 0;
	flags->was_dot = 0;
	flags->width = 0;
	flags->conver = 0;
	flags->nextpls = 0;
	flags->prec = 0;
	flags->prec_enable = 0;
	flags->width_enable = 0;
}

void	print_width(int a, t_data *flags, char spacezero, long long arg)
{
	int b;
	int c;

	c = flags->prec;
	if (c < a)
		c = a;
	else if (arg < 0 && !flags->minus)
		c++;
	if (flags->conver == 's')
		c = flags->prec < a && flags->prec >= 0 ? flags->prec : a;
	b = -1;
	while (++b < flags->width - c)
		ft_putchar_fd(spacezero, 1);
}

void	print_prec(int a, t_data *flags, char *temp, long long arg)
{
	int b;

	b = -1;
	if (flags->prec < a)
		flags->prec = 0;
	if (arg < 0 && (flags->conver == 'd' || flags->conver == 'i'))
	{
		ft_putchar_fd('-', 1);
		if (flags->was_dot && flags->prec)
			flags->prec++;
	}
	while (++b < flags->prec - a)
		ft_putchar_fd('0', 1);
	if (arg < 0 && (flags->conver == 'd' || flags->conver == 'i'))
		ft_putstr_fd(++temp, 1);
	else
		ft_putstr_fd(temp, 1);
}
