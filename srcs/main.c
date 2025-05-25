/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahwang <ahwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:21:04 by ahwang            #+#    #+#             */
/*   Updated: 2025/05/26 01:18:47 by ahwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

void	init_struct_fractol(t_fractol *fractol)
{
	fractol->iter = 200;
	fractol->x_min = -2;
	fractol->x_max = 2;
	fractol->y_min = -2;
	fractol->y_max = 2;
	fractol->color = 0;
}

int	init_struct_mlx(t_mlx *mlx, int fractol_type)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (0);
	if (fractol_type == MANDELBROT)
		mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_X, WIN_Y, "Mandelbrot");
	else if (fractol_type == JULIA)
		mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_X, WIN_Y, "Julia");
	if (!mlx->win)
		return (0);
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_X, WIN_Y);
	if (!mlx->img_ptr)
		return (0);
	mlx->addr = mlx_get_data_addr(mlx->img_ptr, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
	if (!mlx->addr)
		return (0);
	return (1);
}

int	start_mlx(t_fractol *fractol)
{
	t_mlx		mlx;

	fractol->mlx = &mlx;
	init_struct_fractol(fractol);
	if (!init_struct_mlx(fractol->mlx, fractol->type))
	{
		ft_printf("%sError: failed to init mlx\n%s", RED, BLACK);
		return (1);
	}
	print_guide();
	draw_fractol(fractol);
	mlx_hook(fractol->mlx->win, 17, 2, mlx_exit, (void *)0);
	mlx_key_hook(fractol->mlx->win, keys, (void *)fractol);
	mlx_mouse_hook(fractol->mlx->win, zoom, (void *)fractol);
	mlx_loop(fractol->mlx->mlx_ptr);
	return (1);
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (!(check_args_mandelbrot(argc, argv, &fractol)
			|| check_args_julia(argc, argv, &fractol)))
	{
		ft_printf("%sError: arugument error\n\n%s", RED, BLACK);
		print_fractol_list();
		return (1);
	}
	if (!start_mlx(&fractol))
		return (1);
	return (0);
}
