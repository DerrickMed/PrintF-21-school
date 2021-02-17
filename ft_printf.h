/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srorscha <srorscha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 21:35:08 by srorscha          #+#    #+#             */
/*   Updated: 2020/12/20 23:37:35 by srorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define CONVERS "cspdiuxX%"
# define DIGITS "0123456789"

# include <stdarg.h>
# include <string.h>
# include <unistd.h>
//# include <io.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_data
{
	int			width;
	int			prec;
	char		isnull;
	char		minus;
	char		conver;
	char		was_dot;
	char		width_enable;
	char		prec_enable;
	char		nextpls;
}				t_data;

void			print_percent(t_data *flags);
char			*ft_itoa_base(size_t value, int base, int flag);
void			ft_putnstr_fd(char const *s, int limit);
void			print_width(int a, t_data *flags,
							char spacezero, long long arg);
void			print_prec(int a, t_data *flags, char *temp, long long arg);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
char			*ft_itoa(long long n);
int				ft_printf(const char *frmt, ...);
void			clear_flags(t_data *flags);
int				ft_atoi(const char *str);
size_t			ft_strlen(const char *str);
int				ft_isdigit(int c);
void			print_int(t_data *flags, va_list *args);
void			print_x(t_data *flags, va_list *args, int flag);
void			print_pointer(t_data *flags, va_list *args);
void			print_char(t_data *flags, va_list *args);
void			print_string(t_data *flags, va_list *args);
void			print_uint(t_data *flags, va_list *args);
char			*ft_strchr(const char *str, int ch);
void			parse_width_prec(const char *print,
						t_data *flags, va_list *args);
void			print_arg(t_data *flags, va_list *args);
void			check_flags(t_data *flags, const char *print, va_list *args);
void			ft_parser(const char *print, va_list *args);

#endif
