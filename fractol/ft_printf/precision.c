/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:08:04 by marimatt          #+#    #+#             */
/*   Updated: 2022/02/21 14:08:04 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*malloc_empty_string(int len);
int		is_char_in_str(char c, const char *set);
char	*remove_unwanted_char(char **precision, const char *unwanted);
int		ft_atoi(const char *str);
int		ft_strlen_2(char *s);
int		non_zero_string(char *str);
char	*add_char_start(char **str, char c, int num);

char	*get_precision(const char **s, char c)
{
	char	*precision;
	int		ln;
	int		i;

	i = 1;
	ln = 0;
	if (*(*s) != '.')
		return (malloc_empty_string(0));
	(*s)++;
	while (*(*s + ln) != c && is_char_in_str(*(*s + ln), "+- 0123456789") == 1)
		ln++;
	precision = malloc_empty_string(ln + 1);
	if (!precision)
		return (NULL);
	precision[0] = '.';
	while (i < ln + 1)
	{
		precision[i] = **s;
		(*s)++;
		i++;
	}
	return (remove_unwanted_char(&precision, "+ -"));
}

char	*apply_precision_nums(char **str, char *prec)
{
	char	*new;
	int		min_digits;
	int		len;

	new = *str;
	if (new == NULL || prec == NULL)
		return (NULL);
	min_digits = ft_atoi(prec);
	if (min_digits == 0 && non_zero_string(*str) == 0 && ft_strlen_2(prec) > 0)
	{
		free(new);
		return (malloc_empty_string(0));
	}
	len = ft_strlen_2(new);
	if (new[0] == '-')
		len--;
	if (min_digits > len)
	{
		new = add_char_start(str, '0', min_digits - len);
		return (new);
	}
	return (*str);
}

char	*apply_precision_string(char **str, char *precision)
{
	int		max_len;
	int		n;
	char	*tmp;

	if (ft_strlen_2(precision) > 0)
	{
		max_len = ft_atoi(precision);
		tmp = malloc_empty_string(max_len);
		n = 0;
		while ((*str)[n] != '\0' && n < max_len)
		{
			tmp[n] = (*str)[n];
			n++;
		}
		free(*str);
		return (tmp);
	}
	return (*str);
}
