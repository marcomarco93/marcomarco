/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:43:47 by marimatt          #+#    #+#             */
/*   Updated: 2022/04/22 14:15:39 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

int		print_possibile_param(int return_val);

void	set_julia_c(t_param *p, char *re, char *im)
{
	double	tmp_re;
	double	tmp_im;

	tmp_re = (double)ft_atoi(re);
	tmp_im = (double)ft_atoi(im);
	while (tmp_re * tmp_re >= 1)
		tmp_re /= 10;
	while (tmp_im * tmp_im >= 1)
		tmp_im /= 10;
	p->c[0] = tmp_re;
	p->c[1] = tmp_im;
}

int	check_arguments(char **argv, int argc, t_param *param)
{
	if (ft_strlen(argv[1]) != 1 || (argv[1][0] != 'M' && argv[1][0] != 'J'))
		return (-1);
	param->set = argv[1][0];
	if (argc >= 3)
	{
		param->x = ft_atoi(argv[2]);
		param->y = param->x;
		if (argc >= 3)
			param->y = ft_atoi(argv[3]);
	}
	if (argc >= 5)
	{
		if (ft_atoi(argv[4]) > 0)
		{
			param->dx = ft_atoi(argv[4]);
			param->dy = param->dx;
		}
		if (argc >= 5 && ft_atoi(argv[5]) > 0)
			param->dy = ft_atoi(argv[5]);
	}
	if (argc >= 7 && param->set == 'J')
		set_julia_c(param, argv[6], argv[7]);
	return (1);
}

int	print_possibile_param(int return_val)
{
	const char	*s;

	s = "\nError! Possible parameters are (but must be in the following order!):\n\n\
1)\nMUST BE a character 'M' or 'J' for Mandelbrot or Julia sets, respectively.\
\n\n\
2 & 3)\nMUST BE 2 INTS, separated by space, for the X and Y position of the initial rendering\n\
If only one of the two is given, the other is set with the same value. Atoi will be used.\n\
Default X = Y = 0. Values greater than 10 will be ignored.\
\n\n\
4 & 5)\nMUST BE 2 INTS, separated by space and strictly greater than zero!\n\
They stand for the width Dx and height Dy used for plotting.\n\
This means that the render will cover the range for, say, x axis from (X - Dx/2) to (X + Dx/2).\n\
If only one of the two is given, the other is set with the same value.\n\
Default is Dx = Dy = 1. Atoi will be used: if the converted value is <= 0, the default will be used insted.\
\n\n\
6)\nMUST BE an INT, strictly greater than zero! For the number density of evaluated point.\n\
Default is 100; Atoi will be used: if the converted value is <= 0, the default will be used insted.\
\n\n\
Example  ./fractol M 1 2 2 4\n\
\n\
This will render the Mandelbrot set centered at (X = 1, Y = 2) \n\
in the range for axis x = (0 -> 2) and axis y = (0 -> 4)\n\
\n\n\
Extra arguments will be ignored.\n\n\
Plotting of the fractal set can be zoomed till the width of the\n\
window reaches 0.000001 in the corresponding plane.\n\n";
	write(1, s, ft_strlen(s));
	return (return_val);
}
