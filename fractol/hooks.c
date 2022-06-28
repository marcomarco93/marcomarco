/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:10:22 by marimatt          #+#    #+#             */
/*   Updated: 2022/04/22 12:16:17 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

double		ft_abs(double x);
void		draw_fractal(t_param *param);
double		real_coordinate(t_param *p, int i, char axis);
void		change_julia_c(t_param *p);

void	deal_space_key(t_param *p)
{
	if (p->set == 'J')
		change_julia_c(p);
	else
	{
		p->x = 0;
		p->y = 0;
		p->dx = 4;
		p->dy = 4;
	}
	p->color = (p->color + 0.05) * (-1.1);
}

int	close_every(void *param)
{
	t_param	*p;

	p = (t_param *)param;
	mlx_destroy_window(p->mlx_ptr, p->win_ptr);
	exit (0);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_param *p)
{
	if ((button == 1 || button == 4) && p->dx > 0.00001)
	{
		p->dx = p->dx / 1.5;
		p->dy = p->dy / 1.5;
	}
	else if ((button == 2 || button == 5) && p->dx < 10)
	{
		p->dx = p->dx * 1.5;
		p->dy = p->dy * 1.5;
	}
	if (button == 1 || button == 2 || button == 4 || button == 5)
	{
		p->x = real_coordinate(p, x, 'x');
		p->y = real_coordinate(p, y, 'y');
		draw_fractal(p);
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img, 0, 0);
	}
	return (0);
}

int	deal_key(int key, void *param)
{
	t_param	*p;

	p = (t_param *)param;
	if (key == 53 || key == 17)
	{
		mlx_destroy_window(p->mlx_ptr, p->win_ptr);
		exit (0);
	}
	if (key == 49)
		deal_space_key(p);
	if (key == 124)
		p->x += 0.2 * p->dx;
	else if (key == 123)
		p->x -= 0.2 * p->dx;
	else if (key == 126)
		p->y -= 0.2 * p->dy;
	else if (key == 125)
		p->y += 0.2 * p->dy;
	if (key == 124 || key == 125 || key == 126 || key == 123 || key == 49)
	{
		draw_fractal(p);
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img, 0, 0);
	}
	return (0);
}
