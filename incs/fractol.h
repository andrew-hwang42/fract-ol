/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahwang <ahwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:20:21 by ahwang            #+#    #+#             */
/*   Updated: 2025/05/23 23:41:30 by ahwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./define.h"
# include "./struct.h"
# include "../libft/incs/libft.h"
# include "../libft/incs/ft_printf.h"
# include "../mlx_linux/mlx.h"

/* main.c */
void	init_struct_fractol(t_fractol *fractol);
int		init_struct_mlx(t_mlx *mlx, int fractol_type);
int		start_mlx(t_fractol *fractol);
int		main(int argc, char **argv);

/* check_args.c */
int		check_args_mandelbrot(int argc, char **argv, t_fractol *fractol);
int		check_args_julia(int argc, char **argv, t_fractol *fractol);

/* draw_fractol.c */
void	choose_fractol(t_fractol *fractol, float c_re, float c_im);
void	draw_fractol(t_fractol *fractol);

/* mandelbrot.c */
void	mandelbrot(t_fractol *fractol, double c_re, double c_im);

/* julia.c */
void	julia(t_fractol *fractol, double c_re, double c_im);

/* mlx_utils.c */
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
int		mlx_exit(void);
int		keys(int key, t_fractol *fractol);
int		zoom(int key, int x, int y, t_fractol *fractol);

/* utils.c */
int		are_identical(char *s1, char *s2);
void	print_fractol_list(void);
void	print_guide(void);

#endif
