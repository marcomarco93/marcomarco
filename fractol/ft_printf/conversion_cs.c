/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_cs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:06:51 by marimatt          #+#    #+#             */
/*   Updated: 2022/02/21 14:06:51 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(const char *str);
int		is_char_in_str(char c, const char *set);
int		ft_strlen_2(char *s);
char	*ft_strcpy(char **source, int len, int is_free);
char	*apply_precision_string(char **str, char *precision);
char	*apply_width_string(char **str, char *flags, int min_len);

int	put_char(unsigned char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
	return (1);
}

int	put_str(char *s, int *count)
{
	if (!s)
		return (0);
	while (*s != '\0')
	{
		write(1, s, 1);
		(*count)++;
		s++;
	}
	return (1);
}

int	put_c(unsigned char c, int *count, char **fields)
{
	int		min_len;
	int		i;

	min_len = ft_atoi(fields[1]);
	if (min_len > 1)
	{
		i = -1;
		if (is_char_in_str('-', (const char *)fields[0]) == 1)
		{
			put_char(c, count);
			while (++i < min_len - 1)
				put_char(' ', count);
		}
		else if (is_char_in_str('-', (const char *)fields[0]) == 0)
		{
			while (++i < min_len - 1)
				put_char(' ', count);
			put_char(c, count);
		}
		return (1);
	}
	return (put_char(c, count));
}

int	put_s(char *str, int *count, char **fields)
{
	char	*tmp;

	if (str == NULL)
		return (put_s((char *)"(null)", count, fields));
	tmp = ft_strcpy(&str, ft_strlen_2(str), 0);
	tmp = apply_precision_string(&tmp, fields[2]);
	tmp = apply_width_string(&tmp, fields[0], ft_atoi(fields[1]));
	if (tmp == NULL)
		return (0);
	put_str(tmp, count);
	free (tmp);
	return (1);
}
