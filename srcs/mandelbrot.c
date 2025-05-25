/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahwang <ahwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 23:21:18 by ahwang            #+#    #+#             */
/*   Updated: 2025/05/24 20:07:27 by ahwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

void	mandelbrot(t_fractol *fractol, double c_re, double c_im)
{
	int		iter;
	double	x;
	double	y;
	double	tmp;

	x = 0;
	y = 0;
	iter = 1;
	while (iter < fractol->iter)
	{
		tmp = x;
		x = x * x - y * y + c_re;
		y = (2 * tmp * y) + c_im;
		if (x * x + y * y > 4)
		{
			my_mlx_pixel_put(fractol->mlx, fractol->x, fractol->y,
				(fractol->color) + 0x00110011 * iter);
			return ;
		}
		iter++;
	}
	my_mlx_pixel_put(fractol->mlx,
		fractol->x, fractol->y, 0x000000);
}
