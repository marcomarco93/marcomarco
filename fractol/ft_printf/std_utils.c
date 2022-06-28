/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:06:32 by marimatt          #+#    #+#             */
/*   Updated: 2022/02/21 14:06:32 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen_2(char *s)
{
	int	l;

	l = 0;
	while (s[l] != '\0')
		l++;
	return (l);
}

int	is_char_in_str(char c, const char *set)
{
	while (*set != '\0')
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*malloc_empty_string(int len)
{
	int		i;
	char	*flags;

	i = 0;
	flags = (char *)malloc(sizeof(*flags) * (len + 1));
	if (!flags)
		return (NULL);
	while (i < len + 1)
	{
		flags[i] = '\0';
		i++;
	}
	return (flags);
}

char	*ft_strcpy(char **source, int len, int is_free)
{
	char	*new;

	if (*source == NULL)
		return (NULL);
	new = (char *)malloc(sizeof(*new) * (len + 1));
	if (new == NULL)
		return (NULL);
	new[len] = '\0';
	len--;
	while (len >= 0)
	{
		new[len] = (*source)[len];
		len--;
	}
	if (is_free > 0)
		free(*source);
	return (new);
}
