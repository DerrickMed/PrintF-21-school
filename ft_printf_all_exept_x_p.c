/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_all_exept_x_p.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srorscha <srorscha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 21:35:58 by srorscha          #+#    #+#             */
/*   Updated: 2020/12/20 23:35:06 by srorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_int(t_data *flags, va_list *args)
{
	char		*temp;
	size_t		a;
	long long	arg;

	arg = va_arg(*args, int);
	flags->isnull = (flags->minus
		|| (flags->was_dot && flags->prec >= 0)) ? 0 : flags->isnull;
	temp = (flags->was_dot && !flags->prec && arg == 0) ? 0 : ft_itoa(arg);
	a = ft_strlen(temp);
	flags->prec = (flags->width > flags->prec && flags->was_dot
			&& flags->isnull && arg < 0) ? flags->width - 1 : flags->prec;
	flags->prec = (flags->width > flags->prec + 1
			&& flags->isnull) ? flags->width : flags->prec;
	if (!flags->isnull && !flags->minus)
		print_width(a, flags, ' ', arg);
	else if (!flags->minus)
		print_prec(a, flags, temp, arg);
	if (!flags->isnull)
		print_prec(a, flags, temp, arg);
	if (flags->minus)
		print_width(a, flags, ' ', arg);
}

void	print_char(t_data *flags, va_list *args)
{
	int arg;

	arg = va_arg(*args, int);
	flags->prec = 0;
	flags->isnull = (flags->minus) ? 0 : flags->isnull;
	if (!flags->width)
		ft_putchar_fd((char)arg, 1);
	else
	{
		if (!flags->isnull && !flags->minus)
			print_width(1, flags, ' ', arg);
		else if (!flags->minus)
			print_width(1, flags, '0', arg);
		ft_putchar_fd((char)arg, 1);
		if (flags->minus)
			print_width(1, flags, ' ', arg);
	}
}

void	print_percent(t_data *flags)
{
	int arg;

	arg = '%';
	flags->prec = 0;
	flags->isnull = (flags->minus) ? 0 : flags->isnull;
	if (!flags->width)
		ft_putchar_fd((char)arg, 1);
	else
	{
		if (!flags->isnull && !flags->minus)
			print_width(1, flags, ' ', arg);
		else if (!flags->minus)
			print_width(1, flags, '0', arg);
		ft_putchar_fd((char)arg, 1);
		if (flags->minus)
			print_width(1, flags, ' ', arg);
	}
}

void	print_string(t_data *flags, va_list *args)
{
	size_t	a;
	char	*arg;

	arg = va_arg(*args, char *);
	if (!arg)
		arg = "(null)";
	flags->isnull = (flags->minus) ? 0 : flags->isnull;
	if (!flags->width && !flags->prec && !flags->was_dot)
		ft_putstr_fd(arg, 1);
	else
	{
		a = ft_strlen(arg);
		flags->prec = flags->was_dot && flags->prec >= 0 ? flags->prec : (int)a;
		if (!flags->isnull && !flags->minus)
			print_width(a, flags, ' ', 1);
		else if (!flags->minus)
			print_width(a, flags, '0', 1);
		ft_putnstr_fd(arg, flags->prec);
		if (flags->minus)
			print_width(a, flags, ' ', 1);
	}
}

void	print_uint(t_data *flags, va_list *args)
{
	char			*temp;
	size_t			a;
	unsigned int	arg;

	arg = va_arg(*args, unsigned int);
	flags->isnull = (flags->minus
		|| (flags->was_dot && flags->prec >= 0)) ? 0 : flags->isnull;
	temp = (flags->was_dot && !flags->prec && arg == 0) ? 0 : ft_itoa(arg);
	a = ft_strlen(temp);
	flags->prec = (flags->width > flags->prec
		&& flags->isnull) ? flags->width : flags->prec;
	if (!flags->isnull && !flags->minus)
		print_width(a, flags, ' ', arg);
	else if (!flags->minus)
		print_prec(a, flags, temp, arg);
	if (!flags->isnull)
		print_prec(a, flags, temp, arg);
	if (flags->minus)
		print_width(a, flags, ' ', arg);
}
