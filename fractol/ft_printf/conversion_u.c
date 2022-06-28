/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:07:13 by marimatt          #+#    #+#             */
/*   Updated: 2022/02/21 14:07:13 by marimatt         ###   ########.fr       */
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
char	*ft_strcpy(char **source, int len, int is_free);
int		put_str(char *s, int *count);

char	*u_format(char **str, char **fields)
{
	char	*new;

	new = apply_precision_nums(str, fields[2]);
	if (is_char_in_str(' ', (const char *)fields[0]) == 1)
		new = add_char_start(&new, ' ', 1);
	new = apply_width_nums(&new, fields, ft_atoi(fields[1]));
	if (new == NULL)
		free(*str);
	return (new);
}

int	put_u(unsigned int i, char *base, int *count, char **fields)
{
	char			*str;
	int				tmp;

	tmp = 0;
	str = malloc_empty_string(100);
	if (str == NULL)
		return (0);
	put_unsigned_num_base(i, str, &tmp, base);
	str = ft_strcpy(&str, ft_strlen_2(str), 1);
	str = u_format(&str, fields);
	if (str == NULL)
		return (0);
	put_str(str, count);
	free(str);
	return (1);
}
