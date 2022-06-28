/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 11:35:32 by marimatt          #+#    #+#             */
/*   Updated: 2022/05/02 11:35:32 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:06:36 by marimatt          #+#    #+#             */
/*   Updated: 2022/02/21 14:06:36 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen_2(char *s);
char	*add_char_start(char **str, char c, int num);
char	*add_char_end(char **str, char c, int num, int len);

char	*ft_remove_char_begin(char **str, char c)
{
	char	*tmp;
	int		new_len;
	int		old_len;

	if (*str == NULL)
		return (NULL);
	old_len = ft_strlen_2(*str);
	new_len = 0;
	while ((*str)[new_len] != '\0' && (*str)[new_len] == c)
		new_len++;
	new_len = old_len - new_len;
	tmp = (char *)malloc(sizeof(*tmp) * (new_len + 1));
	if (tmp == NULL)
		return (NULL);
	while (new_len >= 0)
	{
		tmp[new_len] = (*str)[old_len];
		new_len--;
		old_len--;
	}
	free(*str);
	return (tmp);
}

char	*add_char_start(char **str, char c, int num)
{
	char	*new;
	char	*s;
	int		n;

	s = *str;
	if (s == NULL)
		return (NULL);
	new = (char *)malloc(sizeof(*new) * (ft_strlen_2(s) + num + 1));
	if (new == NULL)
		return (NULL);
	n = 0;
	while (n < num)
	{
		new[n] = c;
		n++;
	}
	while (s[n - num] != '\0')
	{
		new[n] = s[n - num];
		n++;
	}
	new[n] = '\0';
	free(*str);
	return (new);
}

char	*add_char_end(char **str, char c, int num, int len)
{
	char	*new;
	char	*s;
	int		n;

	s = *str;
	if (s == NULL)
		return (NULL);
	new = (char *)malloc(sizeof(*new) * (len + num + 1));
	if (new == NULL)
		return (NULL);
	n = 0;
	while (s[n] != '\0')
	{
		new[n] = s[n];
		n++;
	}
	while (n < ft_strlen_2(s) + num)
	{
		new[n] = c;
		n++;
	}
	new[n] = '\0';
	free(*str);
	return (new);
}

char	*prepend_string(char **s, char *p)
{
	char	*new;
	int		n;
	int		j;

	if (*s == NULL)
		return (NULL);
	new = (char *)malloc(sizeof(*new) * (ft_strlen_2(*s) + ft_strlen_2(p) + 1));
	if (new == NULL)
		return (NULL);
	n = 0;
	while (p[n] != '\0')
	{
		new[n] = p[n];
		n++;
	}
	j = 0;
	while ((*s)[j] != '\0')
	{
		new[j + n] = (*s)[j];
		j++;
	}
	new[j + n] = '\0';
	free(*s);
	return (new);
}

int	non_zero_string(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '0')
			return (1);
		i++;
	}
	return (0);
}
