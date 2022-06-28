/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numerics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:06:26 by marimatt          #+#    #+#             */
/*   Updated: 2022/02/21 14:06:26 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen_2(char *s);

void	put_unsigned_num_base(unsigned int nb, char *s, int *count, char *base)
{
	unsigned int	len_base;

	len_base = (unsigned int)ft_strlen_2(base);
	if (nb >= len_base)
		put_unsigned_num_base(nb / len_base, s, count, base);
	s[*count] = base[nb % len_base];
	(*count)++;
}

void	put_signed_num_base(int i, char *s, int *count, char *base)
{
	if (i < 0)
	{
		s[0] = '-';
		(*count)++;
		if (i == -2147483648)
		{
			s[1] = '2';
			(*count)++;
			i = -147483648;
		}
		i *= -1;
	}
	put_unsigned_num_base((unsigned int)i, s, count, base);
	return ;
}

void	put_long(unsigned long long int nb, char *s, int *count, char *base)
{
	unsigned long long int	len_base;

	len_base = (unsigned long long int)ft_strlen_2(base);
	if (nb >= len_base)
		put_long(nb / len_base, s, count, base);
	s[*count] = base[nb % len_base];
	(*count)++;
}
