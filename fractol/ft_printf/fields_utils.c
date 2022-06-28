/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fields_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:07:54 by marimatt          #+#    #+#             */
/*   Updated: 2022/02/21 14:07:54 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*malloc_empty_string(int len);
int		is_char_in_str(char c, const char *set);
int		ft_strlen_2(char *s);
char	*ft_strcpy(char **source, int len, int is_free);

char	*remove_unwanted_char(char **precision, const char *unwanted)
{
	char	*new;
	char	*tmp;
	int		n;

	tmp = *precision;
	if (*precision == NULL)
		return (NULL);
	new = malloc_empty_string(ft_strlen_2(*precision));
	n = 0;
	while (*tmp != '\0')
	{
		if (is_char_in_str(*tmp, unwanted) == 0)
		{
			new[n] = *tmp;
			n++;
		}
		tmp++;
	}
	free(*precision);
	return (ft_strcpy(&new, ft_strlen_2(new), 1));
}
