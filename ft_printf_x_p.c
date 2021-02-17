/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srorscha <srorscha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 21:35:47 by srorscha          #+#    #+#             */
/*   Updated: 2020/12/19 23:26:29 by srorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_x(t_data *flags, va_list *args, int flag)
{
	char	*temp;
	size_t	a;
	size_t	arg;

	arg = va_arg(*args, unsigned int);
	flags->isnull = (flags->minus
		|| (flags->was_dot && flags->prec >= 0)) ? 0 : flags->isnull;
	temp = (flags->was_dot
		&& !flags->prec && arg == 0) ? 0 : ft_itoa_base(arg, 16, flag);
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

void	print_pointer(t_data *flags, va_list *args)
{
	char	*temp;
	size_t	a;
	size_t	arg;

	arg = va_arg(*args, unsigned long long int);
	flags->isnull = (flags->minus
		|| (flags->was_dot && flags->prec >= 0)) ? 0 : flags->isnull;
	temp = (flags->was_dot
		&& !flags->prec && arg == 0) ? "0x" : ft_itoa_base(arg, 16, 2);
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
