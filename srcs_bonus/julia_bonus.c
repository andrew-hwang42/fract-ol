/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahwang <ahwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 23:30:40 by ahwang            #+#    #+#             */
/*   Updated: 2025/05/24 00:04:45 by ahwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/fractol_bonus.h"

void	julia(t_fractol *fractol, double c_re, double c_im)
{
	int		iter;
	double	x;
	double	y;
	double	tmp;

	x = c_re;
	y = c_im;
	iter = 1;
	while (iter < fractol->iter)
	{
		tmp = x;
		x = (x * x - y * y) + fractol->julia_x;
		y = (2 * tmp * y) + fractol->julia_y;
		if (x * x + y * y > 4)
		{
			my_mlx_pixel_put(fractol->mlx, fractol->x, fractol->y,
				(fractol->color) + 0x00001111 * iter);
			return ;
		}
		iter++;
	}
	my_mlx_pixel_put(fractol->mlx,
		fractol->x, fractol->y, 0x000000);
}
