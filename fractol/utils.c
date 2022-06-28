/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:39:59 by marimatt          #+#    #+#             */
/*   Updated: 2022/04/22 14:17:54 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

void	init_param(t_param *param, int width, int height)
{
	param->mlx_ptr = NULL;
	param->win_ptr = NULL;
	param->img = NULL;
	param->addr = NULL;
	param->bits_per_pixel = 0;
	param->line_length = 0;
	param->endian = 0;
	param->width = width;
	param->height = height;
	param->set = 'M';
	param->x = 0;
	param->y = 0;
	param->dx = 4;
	param->dy = 4;
	param->lim = 500;
	param->c[0] = 0.0;
	param->c[1] = 0.75;
	param->color = 0;
}

double	ft_abs(double x)
{
	if (x >= 0)
		return (x);
	return (-x);
}

void	square_complex(double *re, double *im)
{
	double	tmp;

	tmp = *re;
	*re = (*re) * (*re) - (*im) * (*im);
	*im = 2.0 * (*im) * tmp;
}

int	create_trgb(unsigned char t, unsigned char r, \
				unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

void	change_julia_c(t_param *p)
{
	double	phase[2];
	double	re_c;
	double	im_c;

	phase[0] = sqrt(3) / 2.0;
	phase[1] = 0.5;
	re_c = phase[0] * p->c[0] + phase[1] * p->c[1];
	im_c = -phase[1] * p->c[0] + phase[0] * p->c[1];
	p->c[0] = re_c;
	p->c[1] = im_c;
	p->x = 0;
	p->y = 0;
	p->dx = 4;
	p->dy = 4;
}
