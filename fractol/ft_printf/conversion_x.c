/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:07:21 by marimatt          #+#    #+#             */
/*   Updated: 2022/02/21 14:07:21 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(const char *str);
int		ft_strlen_2(char *s);
int		is_char_in_str(char c, const char *set);
char	*apply_precision_nums(char **str, char *precision);
char	*apply_width_nums(char **str, char **fields, int min_len);
char	*malloc_empty_string(int len);
char	*add_char_start(char **str, char c, int num);
void	put_unsigned_num_base(unsigned int nb, char *s, int *count, char *base);
char	*prepend_string(char **str, char *pfx);
char	*ft_strcpy(char **source, int len, int is_free);
int		non_zero_string(char *str);
int		put_str(char *s, int *count);

char	*x_format(char **str, char **f, char *zero_x)
{
	char	*s;

	s = apply_precision_nums(str, f[2]);
	if (is_char_in_str('#', (const char *)f[0]) == 1 && non_zero_string(s) == 1)
		s = prepend_string(&s, zero_x);
	if (is_char_in_str(' ', (const char *)f[0]) == 1)
		s = add_char_start(&s, ' ', 1);
	s = apply_width_nums(&s, f, ft_atoi(f[1]));
	if (s == NULL)
		free(*str);
	return (s);
}

int	put_x(unsigned int i, char *base, int *count, char **fields)
{
	char			*str;
	int				tmp;

	tmp = 0;
	str = malloc_empty_string(100);
	if (str == NULL)
		return (0);
	put_unsigned_num_base(i, str, &tmp, base);
	str = ft_strcpy(&str, ft_strlen_2(str), 1);
	if (is_char_in_str('A', base) == 1)
		str = x_format(&str, fields, "0X");
	else
		str = x_format(&str, fields, "0x");
	if (str == NULL)
		return (0);
	put_str(str, count);
	free(str);
	return (1);
}
