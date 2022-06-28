/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:07:07 by marimatt          #+#    #+#             */
/*   Updated: 2022/02/21 14:07:07 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(const char *str);
char	*apply_precision_nums(char **str, char *precision);
char	*apply_width_nums(char **str, char **fields, int min_len);
char	*malloc_empty_string(int len);
char	*prepend_string(char **str, char *pfx);
void	put_long(unsigned long long int nb, char *s, int *count, char *base);
int		put_str(char *s, int *count);

char	*p_format(char **str, char **fields)
{
	char	*tmp;

	tmp = *str;
	if (tmp == NULL)
		return (NULL);
	tmp = apply_precision_nums(&tmp, fields[2]);
	tmp = prepend_string(&tmp, "0x");
	tmp = apply_width_nums(&tmp, fields, ft_atoi(fields[1]));
	if (tmp == NULL)
		free(*str);
	return (tmp);
}

int	put_adress(unsigned long long int i, int *count, char **fl)
{
	char			*str;
	int				tmp;

	tmp = 0;
	str = malloc_empty_string(100);
	if (str == NULL)
		return (0);
	put_long(i, str, &tmp, "0123456789abcdef");
	str = p_format(&str, fl);
	if (str == NULL)
		return (0);
	put_str(str, count);
	free(str);
	return (1);
}
