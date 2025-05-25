/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahwang <ahwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 00:04:27 by ahwang            #+#    #+#             */
/*   Updated: 2025/05/24 00:12:14 by ahwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/fractol_bonus.h"

void	burning_ship(t_fractol *fractol, double c_re, double c_im)
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
		x = x * x - y * y - c_re;
		y = fabs(2 * tmp * y) - c_im;
		if (x * x + y * y > 4)
		{
			my_mlx_pixel_put(fractol->mlx, fractol->x, fractol->y,
				(fractol->color) + 0x00110000 * iter);
			return ;
		}
		iter++;
	}
	my_mlx_pixel_put(fractol->mlx,
		fractol->x, fractol->y, 0x000000);
}
