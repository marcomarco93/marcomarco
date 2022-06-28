/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:05:14 by marimatt          #+#    #+#             */
/*   Updated: 2022/02/21 14:05:14 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_char_in_str(char c, const char *set);
int		put_id(int i, char *base, int *count, char **fields);
int		put_u(unsigned int i, char *base, int *count, char **fields);
int		put_x(unsigned int i, char *base, int *count, char **fields);
int		put_adress(unsigned long long int i, int *count, char **fl);
int		put_c(unsigned char c, int *count, char **fields);
int		put_s(char *str, int *count, char **fields);
int		put_char(unsigned char c, int *count);
int		put_str(char *s, int *count);

int	is_valid_format(const char *fmt, char **conv)
{
	fmt++;
	while (is_char_in_str(*fmt, "-#0 +") == 1)
		fmt++;
	while (is_char_in_str(*fmt, "+- 0123456789") == 1)
		fmt++;
	if (*fmt == '.')
	{
		fmt++;
		while (is_char_in_str(*fmt, "+- 0123456789") == 1)
			fmt++;
	}
	if (is_char_in_str(*fmt, "cspdiuXx%") == 1)
	{
		*conv = (char *)fmt;
		return (1);
	}
	else
		return (0);
}

int	print_by_format(const char conv, va_list *ptr, int *c, char **fld)
{
	if (conv == 'i' || conv == 'd')
		return (put_id(va_arg(*ptr, int), "0123456789", c, fld));
	if (conv == 'u')
		return (put_u(va_arg(*ptr, unsigned int), "0123456789", c, fld));
	if (conv == 'x')
		return (put_x(va_arg(*ptr, unsigned int), "0123456789abcdef", c, fld));
	if (conv == 'X')
		return (put_x(va_arg(*ptr, unsigned int), "0123456789ABCDEF", c, fld));
	if (conv == 'p')
		return (put_adress(va_arg(*ptr, unsigned long long int), c, fld));
	if (conv == 'c')
		return (put_c((unsigned char)va_arg(*ptr, int), c, fld));
	if (conv == 's')
		return (put_s((char *)va_arg(*ptr, const char *), c, fld));
	if (conv == '%')
		return (put_char('%', c));
	return (0);
}
