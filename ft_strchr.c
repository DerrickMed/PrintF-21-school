/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srorscha <srorscha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 21:35:03 by srorscha          #+#    #+#             */
/*   Updated: 2020/12/19 22:08:37 by srorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *str, int ch)
{
	char	cc;

	cc = (char)ch;
	while (*str)
	{
		if (*str == cc)
		{
			return ((char*)str);
		}
		str++;
	}
	if (*str == 0 && ch == 0)
		return ((char*)str);
	return (0);
}
