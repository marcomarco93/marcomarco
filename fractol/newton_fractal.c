/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:25:38 by marimatt          #+#    #+#             */
/*   Updated: 2022/04/22 14:21:28 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

double		ft_abs(double x);
void		square_complex(double *re, double *im);
int			create_trgb(unsigned char t, unsigned char r, \
				unsigned char g, unsigned char b);

double	ft_min(double x, double y)
{
	if (x <= y)
		return (x);
	return (y);
}

double	complex_dist(double *re, double *im, double re_z2, double im_z2)
{
	double	dist1;
	double	dist2;
	double	dist3;

	dist1 = pow(pow(re[0] - re_z2, 2) + pow(im[0] - im_z2, 2), 0.5);
	dist2 = pow(pow(re[1] - re_z2, 2) + pow(im[1] - im_z2, 2), 0.5);
	dist3 = pow(pow(re[2] - re_z2, 2) + pow(im[2] - im_z2, 2), 0.5);
	return (ft_min(dist1, ft_min(dist2, dist3)));
}

int	newton_pshyco(double re, double im, double n, double dist)
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
	dist = 0;
	im = 0;
	return (create_trgb(0, ft_abs(r), ft_abs(g), ft_abs(b)));
}

void	init_roots(double **roots_re, double **roots_im)
{
	*roots_re = (double *)malloc(sizeof(**roots_re) * 3);
	*roots_im = (double *)malloc(sizeof(**roots_im) * 3);
	(*roots_re)[0] = 1.0;
	(*roots_re)[1] = -0.5;
	(*roots_re)[2] = -0.5;
	(*roots_im)[0] = 0.0;
	(*roots_im)[1] = 0.5 * sqrt(3.0);
	(*roots_im)[2] = -0.5 * sqrt(3.0);
}

int	newton_point_color(double x, double y, int lim)
{
	double	im;
	double	re;
	double	*roots_re;
	double	*roots_im;
	int		n;

	init_roots(&roots_re, &roots_im);
	n = 0;
	re = x;
	im = y;
	while (n < lim && complex_dist(roots_re, roots_im, re, im) < 3)
	{
		x = re;
		re += (re * re - im * im) / pow(re * re + im * im, 2);
		im -= 2 * x * im / pow(x * x + im * im, 2);
		if (complex_dist(roots_re, roots_im, re, im) < 0.05)
			break ;
		n++;
	}
	free(roots_im);
	free(roots_re);
	if (complex_dist(roots_re, roots_im, re, im) < 0.05)
		return (create_trgb(0, 0, 0, 0));
	return (newton_pshyco(re, im, (double)n / (double)lim, \
		complex_dist(roots_re, roots_im, re, im)));
}
