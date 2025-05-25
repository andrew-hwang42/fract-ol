/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahwang <ahwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:21:12 by ahwang            #+#    #+#             */
/*   Updated: 2025/05/26 01:15:48 by ahwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
	void	*img_ptr;
	char	*addr;
	int		line_length;
	int		bits_per_pixel;
	int		endian;
}	t_mlx;

/* x axis is for real, y axis is for imaginary */
typedef struct s_fractol
{
	int		type;
	int		iter;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	int		x;
	int		y;
	double	julia_x;
	double	julia_y;
	int		color;
	t_mlx	*mlx;
}	t_fractol;

#endif
