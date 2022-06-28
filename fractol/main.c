/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:21:04 by marimatt          #+#    #+#             */
/*   Updated: 2022/04/22 14:14:53 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

void	init_param(t_param *param, int width, int height);
int		print_possibile_param(int return_val);
int		check_arguments(char **argv, int argc, t_param *param);
void	draw_fractal(t_param *param);
int		deal_key(int key, void *param);
int		close_every(void *param);
int		mouse_hook(int button, int x, int y, t_param *p);

int	main(int argc, char **argv)
{
	t_param	param;
	int		size;

	size = 800;
	if (argc < 2)
		return (print_possibile_param(0));
	init_param(&param, size, size);
	if (check_arguments(argv, argc, &param) < 0)
		return (print_possibile_param(0));
	param.mlx_ptr = mlx_init();
	param.win_ptr = mlx_new_window(param.mlx_ptr, size, size, "Fractal");
	param.img = mlx_new_image(param.mlx_ptr, size, size);
	param.addr = mlx_get_data_addr(param.img, &param.bits_per_pixel, \
									&param.line_length, &param.endian);
	draw_fractal(&param);
	mlx_key_hook(param.win_ptr, deal_key, (void *)&param);
	mlx_hook(param.win_ptr, 17, 0, close_every, (void *)&param);
	mlx_hook(param.win_ptr, 4, (1L << 2), mouse_hook, &param);
	mlx_put_image_to_window(param.mlx_ptr, param.win_ptr, param.img, 0, 0);
	mlx_loop(param.mlx_ptr);
	return (0);
}
