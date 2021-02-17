/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srorscha <srorscha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 21:35:18 by srorscha          #+#    #+#             */
/*   Updated: 2020/12/19 22:18:37 by srorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putstr_fd(char const *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

void		ft_putnstr_fd(char const *s, int limit)
{
	if (!s)
		return ;
	while (*s && limit > 0)
	{
		ft_putchar_fd(*s, 1);
		s++;
		limit--;
	}
}
