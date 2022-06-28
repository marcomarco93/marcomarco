/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_id.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:06:57 by marimatt          #+#    #+#             */
/*   Updated: 2022/02/21 14:06:57 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(const char *str);
int		is_char_in_str(char c, const char *set);
int		ft_strlen_2(char *s);
char	*ft_strcpy(char **source, int len, int is_free);
char	*apply_precision_nums(char **str, char *precision);
char	*apply_width_nums(char **str, char **fields, int min_len);
char	*add_char_start(char **str, char c, int num);
char	*add_char_end(char **str, char c, int num, int len);
char	*malloc_empty_string(int len);
void	put_signed_num_base(int i, char *s, int *count, char *base);
int		put_str(char *s, int *count);

void	put_sign_front(char **str)
{
	char	*tmp;
	int		i;
	char	c;

	if (*str == NULL)
		return ;
	tmp = *str;
	i = 0;
	c = tmp[0];
	if (c == ' ')
		return ;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '+' || tmp[i] == '-')
		{
			tmp[0] = tmp[i];
			tmp[i] = c;
			return ;
		}
		i++;
	}
}

char	*id_format(char **str, char **fld)
{
	char	*new;

	new = *str;
	new = apply_precision_nums(&new, fld[2]);
	put_sign_front(&new);
	if (is_char_in_str(' ', fld[0]) == 1 && is_char_in_str('+', fld[0]) == 0 && \
		is_char_in_str('-', new) == 0)
		new = add_char_start(&new, ' ', 1);
	put_sign_front(&new);
	new = apply_width_nums(&new, fld, ft_atoi(fld[1]));
	if (is_char_in_str('+', fld[0]) == 1 && is_char_in_str('-', new) == 0)
		new = add_char_start(&new, '+', 1);
	put_sign_front(&new);
	if (new == NULL)
		free(*str);
	return (new);
}

int	put_id(int i, char *base, int *count, char **fields)
{
	char	*str;
	int		tmp;

	tmp = 0;
	str = malloc_empty_string(100);
	if (str == NULL)
		return (0);
	put_signed_num_base(i, str, &tmp, base);
	str = ft_strcpy(&str, ft_strlen_2(str), 1);
	str = id_format(&str, fields);
	if (str == NULL)
		return (0);
	put_str(str, count);
	free(str);
	return (1);
}
