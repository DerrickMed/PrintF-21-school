/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srorscha <srorscha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:25:22 by srorscha          #+#    #+#             */
/*   Updated: 2020/12/19 22:20:49 by srorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(size_t value, int base, int upstr)
{
	static char	str[20];
	int			size;
	char		*tab;
	int			flag;
	size_t		tmp;

	size = 0;
	tab = !upstr ? "0123456789ABCDEF" : "0123456789abcdef";
	tmp = value;
	while (tmp /= base)
		size++;
	flag = upstr == 2 ? 2 : 0;
	size = size + flag + 1;
	str[size] = '\0';
	str[0] = upstr == 2 ? '0' : 0;
	str[1] = upstr == 2 ? 'x' : 0;
	while (size > flag)
	{
		str[size - 1] = tab[value % base];
		size--;
		value /= base;
	}
	return (str);
}
