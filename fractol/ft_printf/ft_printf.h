/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:05:17 by marimatt          #+#    #+#             */
/*   Updated: 2022/02/21 14:05:17 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);

// int		ft_atoi(const char *str);
// int		is_valid_format(const char *fmt, char **conv);
// int		print_by_format(const char conv, va_list *ptr, int *c, char **fld);

// void	put_unsigned_num_base(unsigned int nb, char *s, int *count, char *base);
// void	put_signed_num_base(int i, char *s, int *count, char *base);
// void	put_long(unsigned long long int nb, char *s, int *count, char *base);

// int		ft_strlen_2(char *s);
// int		is_char_in_str(char c, const char *set);
// char	*malloc_empty_string(int len);
// char	*ft_strcpy(char **source, int len, int is_free);
// char	*ft_remove_char_begin(char **str, char c);
// char	*add_char_start(char **str, char c, int num);
// char	*add_char_end(char **str, char c, int num, int len);
// char	*prepend_string(char **str, char *pfx);
// int		non_zero_string(char *str);

// int		put_id(int i, char *base, int *count, char **fields);
// int		put_u(unsigned int i, char *base, int *count, char **fields);
// int		put_x(unsigned int i, char *base, int *count, char **fields);
// int		put_adress(unsigned long long int i, int *count, char **fl);
// int		put_c(unsigned char c, int *count, char **fields);
// int		put_s(char *str, int *count, char **fields);

// int		put_char(unsigned char c, int *count);
// int		put_str(char *s, int *count);

// char	*get_flags(const char **str, char conversion);
// char	*get_precision(const char **str, char conversion);
// char	*get_width(const char **str, char conversion);

// char	*simplify_flags(char **flags);
// char	*apply_precision_string(char **str, char *precision);
// char	*apply_precision_nums(char **str, char *precision);
// char	*apply_width_nums(char **str, char **fields, int min_len);
// char	*apply_width_string(char **str, char *flags, int min_len);
// char	*remove_unwanted_char(char **precision, const char *unwanted);

#endif
