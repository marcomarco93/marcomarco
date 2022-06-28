/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:06:26 by marimatt          #+#    #+#             */
/*   Updated: 2022/04/22 14:00:26 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

int		mandelbrot_point_color(double x, double y, int lim, double color_type);
int		julia_point_color(double point[2], double c[2], int lim, \
		double color_type);
int		newton_point_color(double x, double y, int lim);

void	my_mlx_pixel_put(t_param *p, int x, int y, int color)
{
	char	*dst;

	dst = p->addr + (y * p->line_length + x * (p->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

double	real_coordinate(t_param *p, int i, char axis)
{
	if (axis == 'x')
		return ((p->x - 0.5 * p->dx) + p->dx * ((double)i / (double)p->width));
	else
		return ((p->y - 0.5 * p->dy) + p->dy * ((double)i / (double)p->height));
}

int	is_point_in_set(t_param *p, int i, int j)
{
	double	point[2];

	point[0] = real_coordinate(p, i, 'x');
	point[1] = real_coordinate(p, j, 'y');
	if (p->set == 'M')
		return (mandelbrot_point_color(point[0], point[1], p->lim, p->color));
	else if (p->set == 'J')
		return (julia_point_color(point, p->c, p->lim, p->color));
	else if (p->set == 'N')
		return (newton_point_color(point[0], point[1], 100));
	return (0);
}

void	draw_fractal(t_param *param)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	while (i < param->width)
	{
		j = 0;
		while (j < param->height)
		{
			color = is_point_in_set(param, i, j);
			my_mlx_pixel_put(param, i, j, color);
			j++;
		}
		i++;
	}
}
