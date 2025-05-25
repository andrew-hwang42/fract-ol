/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahwang <ahwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:54:48 by ahwang            #+#    #+#             */
/*   Updated: 2025/05/26 01:19:35 by ahwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/fractol_bonus.h"

void	choose_fractol(t_fractol *fractol, float c_re, float c_im)
{
	if (fractol->type == MANDELBROT)
		mandelbrot(fractol, c_re, c_im);
	else if (fractol->type == JULIA)
		julia(fractol, c_re, c_im);
	else if (fractol->type == BURNING_SHIP)
		burning_ship(fractol, c_re, c_im);
}

void	draw_fractol(t_fractol *fractol)
{
	double	c_re;
	double	c_im;

	fractol->x = 0;
	fractol->y = 0;
	mlx_clear_window(fractol->mlx->mlx_ptr, fractol->mlx->win);
	while (fractol->y < WIN_Y)
	{
		while (fractol->x < WIN_X)
		{
			c_re = fractol->x_min
				+ (fractol->x
					* (fractol->x_max - fractol->x_min) / WIN_X);
			c_im = fractol->y_max
				- (fractol->y
					* (fractol->y_max - fractol->y_min) / WIN_Y);
			choose_fractol(fractol, c_re, c_im);
			fractol->x++;
		}
		fractol->y++;
		fractol->x = 0;
	}
	mlx_put_image_to_window(fractol->mlx->mlx_ptr,
		fractol->mlx->win, fractol->mlx->img_ptr, 0, 0);
}
