/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahwang <ahwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:20:21 by ahwang            #+#    #+#             */
/*   Updated: 2025/05/24 00:10:16 by ahwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include <math.h>
# include "./define_bonus.h"
# include "./struct_bonus.h"
# include "../libft/incs/libft.h"
# include "../libft/incs/ft_printf.h"
# include "../mlx_linux/mlx.h"

/* main_bonus.c */
void	init_struct_fractol(t_fractol *fractol);
int		init_struct_mlx(t_mlx *mlx, int fractol_type);
int		start_mlx(t_fractol *fractol);
int		main(int argc, char **argv);

/* check_args_bonus.c */
int		check_args_mandelbrot(int argc, char **argv, t_fractol *fractol);
int		check_args_julia(int argc, char **argv, t_fractol *fractol);
int		check_args_burning_ship(int argc, char **argv, t_fractol *fractol);

/* draw_fractol_bonus.c */
void	choose_fractol(t_fractol *fractol, float c_re, float c_im);
void	draw_fractol(t_fractol *fractol);

/* mandelbrot_bonus.c */
void	mandelbrot(t_fractol *fractol, double c_re, double c_im);

/* julia_bonus.c */
void	julia(t_fractol *fractol, double c_re, double c_im);

/* burning_ship_bonus.c */
void	burning_ship(t_fractol *fractol, double c_re, double c_im);

/* mlx_utils_bonus.c */
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
int		mlx_exit(void);
int		keys(int key, t_fractol *fractol);
int		zoom(int key, int x, int y, t_fractol *fractol);

/* utils_bonus.c */
int		are_identical(char *s1, char *s2);
void	print_fractol_list(void);
void	print_guide(void);

#endif
