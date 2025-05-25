/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahwang <ahwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 20:24:05 by ahwang            #+#    #+#             */
/*   Updated: 2025/05/26 01:19:48 by ahwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/fractol_bonus.h"

int	check_args_mandelbrot(int argc, char **argv, t_fractol *fractol)
{
	if (argc != 2)
		return (0);
	if (!(are_identical(argv[1], "Mandelbrot")
			|| are_identical(argv[1], "MANDELBROT")
			|| are_identical(argv[1], "mandelbrot")
			|| are_identical(argv[1], "1")))
		return (0);
	fractol->type = MANDELBROT;
	return (1);
}

int	check_args_julia(int argc, char **argv, t_fractol *fractol)
{
	if (argc != 4)
		return (0);
	if (!(are_identical(argv[1], "Julia")
			|| are_identical(argv[1], "JULIA")
			|| are_identical(argv[1], "julia")
			|| are_identical(argv[1], "2")))
		return (0);
	if (ft_atod(argv[2]) == ERROR_FT_ATOD
		|| !(-1 <= ft_atod(argv[2]) && ft_atod(argv[2]) <= 1))
		return (0);
	if (ft_atod(argv[3]) == ERROR_FT_ATOD
		|| !(-1 <= ft_atod(argv[3]) && ft_atod(argv[3]) <= 1))
		return (0);
	fractol->type = JULIA;
	fractol->julia_x = ft_atod(argv[2]);
	fractol->julia_y = ft_atod(argv[3]);
	return (1);
}

int	check_args_burning_ship(int argc, char **argv, t_fractol *fractol)
{
	if (argc != 2)
		return (0);
	if (!(are_identical(argv[1], "Burning_ship")
			|| are_identical(argv[1], "BURNING_SHIP")
			|| are_identical(argv[1], "burning_ship")
			|| are_identical(argv[1], "3")))
		return (0);
	fractol->type = BURNING_SHIP;
	return (1);
}
