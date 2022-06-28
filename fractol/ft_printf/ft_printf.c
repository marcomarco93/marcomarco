/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:05:09 by marimatt          #+#    #+#             */
/*   Updated: 2022/02/21 14:05:09 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_valid_format(const char *fmt, char **conv);
int		print_by_format(const char conv, va_list *ptr, int *c, char **fld);
int		put_char(unsigned char c, int *count);
char	*get_flags(const char **str, char conversion);
char	*get_precision(const char **str, char conversion);
char	*get_width(const char **str, char conversion);

static char	**get_fields(const char *format, char conversion)
{
	char	**fields;

	format++;
	fields = (char **)malloc(sizeof(*fields) * 3);
	if (fields == NULL)
		return (NULL);
	fields[0] = get_flags(&format, conversion);
	fields[1] = get_width(&format, conversion);
	fields[2] = get_precision(&format, conversion);
	if (fields[0] == NULL || fields[1] == NULL || fields[2] == NULL)
	{
		if (fields[0] != NULL)
			free(fields[0]);
		if (fields[1] != NULL)
			free(fields[1]);
		if (fields[2] != NULL)
			free(fields[2]);
		return (NULL);
	}
	else
		return (fields);
}

static const char	*doo(const char *fmt, char *conv, int *count, va_list *ptr)
{
	char	**fields;
	int		check;

	fields = get_fields(fmt, *conv);
	if (fields == NULL || ptr == NULL)
	{
		*count = -1;
		return (NULL);
	}
	check = print_by_format(*conv, ptr, count, fields);
	if (check == 0)
	{
		*count = -1;
		conv = NULL;
	}
	free(fields[0]);
	free(fields[1]);
	free(fields[2]);
	free(fields);
	return ((const char *)conv);
}

int	ft_printf(const char *format, ...)
{
	va_list	ptr;
	int		count;
	char	*conversion;

	count = 0;
	va_start(ptr, format);
	if (!format)
		return (-1);
	while (*format != '\0')
	{
		if (*format == '%' && is_valid_format(format, &conversion) == 1)
		{
			format = doo(format, conversion, &count, &ptr);
			if (format == NULL)
				break ;
		}
		else if (*format == '%' && *(format + 1) == '\0')
			return (count);
		else
			put_char(*format, &count);
		format++;
	}
	va_end(ptr);
	return (count);
}
