/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:19:51 by marimatt          #+#    #+#             */
/*   Updated: 2022/04/22 12:25:03 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

double		ft_abs(double x);
void		square_complex(double *re, double *im);
int			create_trgb(unsigned char t, unsigned char r, \
				unsigned char g, unsigned char b);

int	mandelbrot_pshyco(double re, double im, double n, double color_type)
{
	double	intensity;
	double	r;
	double	g;
	double	b;

	intensity = 255 * pow(1 - n, 6);
	r = intensity;
	g = pow(intensity, 2) / pow(255.0, 1);
	b = pow(intensity, 3) / pow(255.0, 2);
	re = 0;
	im = 0;
	color_type = 0;
	return (create_trgb(0, ft_abs(r), ft_abs(g), ft_abs(b)));
}

int	julia_pshyco(double re, double im, double n, double color_type)
{
	double	intensity;
	double	r;
	double	g;
	double	b;

	intensity = 255 * pow(1 - n, 6);
	r = intensity;
	if (color_type > 0)
	{
		g = ft_abs(sin(re)) * pow(intensity, 2) / pow(255.0, 1);
		b = ft_abs(cos(im)) * pow(intensity, 2) / pow(255.0, 1);
	}
	else
	{
		g = pow(intensity, 2) / pow(255.0, 1);
		b = pow(intensity, 2) / pow(255.0, 1);
	}
	return (create_trgb(0, ft_abs(r), ft_abs(g), ft_abs(b)));
}

int	mandelbrot_point_color(double x, double y, int lim, double color_type)
{
	double	im;
	double	re;
	int		n;

	n = 0;
	re = x;
	im = y;
	while (n < lim)
	{
		if (re * re + im * im > 4)
			return (julia_pshyco(re, im, (double)n / (double)lim, \
					color_type));
		square_complex(&re, &im);
		re += x;
		im += y;
		n++;
	}
	return (create_trgb(0, 0, 0, 0));
}

int	julia_point_color(double point[2], double c[2], int lim, double color_type)
{
	double	im;
	double	re;
	int		n;

	n = 0;
	re = point[0];
	im = point[1];
	while (n < lim)
	{
		if (re * re + im * im >= 4)
			return (julia_pshyco(re, im, (double)n / (double)lim, color_type));
		square_complex(&re, &im);
		re += c[0];
		im += c[1];
		n++;
	}
	return (create_trgb(0, 0, 0, 0));
}
