/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahwang <ahwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:20:01 by ahwang            #+#    #+#             */
/*   Updated: 2025/05/26 01:16:08 by ahwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

/* color */
# define BLACK			"\x1b[0m"
# define RED			"\x1b[31m"

/* libft */
# define ERROR_FT_ATOD	-9999.9

/* fractal type */
# define MANDELBROT	1
# define JULIA		2

/* mlx */
# define WIN_X		500
# define WIN_Y		500

/* keys:
	ESC: escape
	MOUSE_SCROLL_UP: zoom in
	MOUSE_SCROLL_DOWN: zoom out
	KEY_C: change color
	KEY_A: julia set: decrease real number(-x)
	KEY_D: julia set: increase real number(+x)
	KEY_S: julia set: decrease imaginary number(-y)
	KEY_W: julia set: increase imaginary number(+y) */
# define ESC		0xFF1B
# define SCROLL_UP	4
# define SCROLL_DOWN	5
# define KEY_C		0x63

# define KEY_W		0x77
# define KEY_A		0x61
# define KEY_S		0x73
# define KEY_D		0x64

#endif