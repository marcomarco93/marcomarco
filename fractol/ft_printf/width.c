/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:08:09 by marimatt          #+#    #+#             */
/*   Updated: 2022/02/21 14:08:09 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_char_in_str(char c, const char *set);
char	*malloc_empty_string(int len);
char	*remove_unwanted_char(char **precision, const char *unwanted);
int		ft_strlen_2(char *s);
char	*add_char_start(char **str, char c, int num);
char	*add_char_end(char **str, char c, int num, int len);

char	*get_width(const char **s, char c)
{
	char	*width;
	int		ln;
	int		i;

	ln = 0;
	while (*(*s + ln) != c && is_char_in_str(*(*s + ln), "+- 0123456789") == 1)
		ln++;
	i = 0;
	width = malloc_empty_string(ln);
	while (i < ln)
	{
		width[i] = **s;
		(*s)++;
		i++;
	}
	return (remove_unwanted_char(&width, "+ -"));
}

char	*apply_width_nums(char **str, char **fields, int min_len)
{
	char	*tmp;
	int		len;

	if (*str == NULL || fields == NULL)
		return (NULL);
	len = ft_strlen_2(*str);
	if (min_len > len)
	{
		if (is_char_in_str('-', (const char *)fields[0]) == 1)
			tmp = add_char_end(str, ' ', min_len - len, ft_strlen_2(*str));
		else
		{
			if (is_char_in_str('0', (const char *)fields[0]) == 1 \
				&& ft_strlen_2(fields[2]) == 0)
				tmp = add_char_start(str, '0', min_len - len);
			else
				tmp = add_char_start(str, ' ', min_len - len);
		}
		return (tmp);
	}
	return (*str);
}

char	*apply_width_string(char **str, char *flags, int min_len)
{
	char	*new;
	int		len;

	new = *str;
	if (new == NULL || flags == NULL)
		return (NULL);
	len = ft_strlen_2(new);
	if (len < min_len)
	{
		if (is_char_in_str('-', (const char *)flags) == 1)
			new = add_char_end(str, ' ', min_len - len, ft_strlen_2(*str));
		else
			new = add_char_start(str, ' ', min_len - len);
	}
	return (new);
}
