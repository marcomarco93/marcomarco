/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:07:59 by marimatt          #+#    #+#             */
/*   Updated: 2022/02/21 14:07:59 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*malloc_empty_string(int len);
int		is_char_in_str(char c, const char *set);
int		ft_strlen_2(char *s);

char	*simplify_flags(char **flags)
{
	char	*new;
	int		n;

	new = *flags;
	if (new == NULL)
		return (NULL);
	if (is_char_in_str('-', new) == 1 && is_char_in_str('0', new) == 1)
	{
		n = 0;
		while (new[n] != '0')
			n++;
		new[n] = '-';
	}
	if (is_char_in_str('+', new) == 1 && is_char_in_str(' ', new) == 1)
	{
		n = 0;
		while (new[n] != ' ')
			n++;
		new[n] = '+';
	}
	return (new);
}

char	*get_flags(const char **str, char conversion)
{
	char	*flags;
	int		i;

	i = 0;
	flags = malloc_empty_string(ft_strlen_2("-#0 +"));
	while (**str != conversion && is_char_in_str(**str, "-#0 +") == 1)
	{
		if (is_char_in_str(**str, flags) == 0)
		{
			flags[i] = **str;
			i++;
		}
		(*str)++;
	}
	return (simplify_flags(&flags));
}
