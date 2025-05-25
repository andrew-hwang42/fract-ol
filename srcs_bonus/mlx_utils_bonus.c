/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahwang <ahwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:21:10 by ahwang            #+#    #+#             */
/*   Updated: 2025/05/26 01:19:13 by ahwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/fractol_bonus.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (x * mlx->bits_per_pixel / 8) + (y * mlx->line_length);
	*(unsigned int *)dst = color;
}

int	mlx_exit(void)
{
	exit(0);
	return (0);
}

int	keys(int key, t_fractol *fractol)
{
	if (key == ESC)
	{
		exit(0);
		return (0);
	}
	if (key == KEY_C)
		fractol->color += 0x00abc123;
	if (key == KEY_A)
		fractol->julia_x -= 0.05;
	if (key == KEY_D)
		fractol->julia_x += 0.05;
	if (key == KEY_S)
		fractol->julia_y -= 0.05;
	if (key == KEY_W)
		fractol->julia_y += 0.05;
	draw_fractol(fractol);
	return (0);
}

int	zoom(int key, int x, int y, t_fractol *fractol)
{
	float	dx;
	float	dy;

	dx = (fractol->x_max - fractol->x_min) / WIN_X;
	dy = (fractol->y_max - fractol->y_min) / WIN_Y;
	if (key == SCROLL_UP)
	{
		fractol->x_min = (fractol->x_min + (dx * x * 0.5));
		fractol->x_max = (fractol->x_max - (dx * (WIN_X - x) * 0.5));
		fractol->y_min = (fractol->y_min + (dy * (WIN_Y - y) * 0.5));
		fractol->y_max = (fractol->y_max - (dy * y * 0.5));
	}
	if (key == SCROLL_DOWN)
	{
		fractol->x_min = (fractol->x_min - (dx * x * 0.5));
		fractol->x_max = (fractol->x_max + (dx * (WIN_X - x) * 0.5));
		fractol->y_min = (fractol->y_min - (dy * (WIN_Y - y) * 0.5));
		fractol->y_max = (fractol->y_max + (dy * y * 0.5));
	}
	draw_fractol(fractol);
	return (0);
}
