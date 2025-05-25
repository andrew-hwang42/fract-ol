/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahwang <ahwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:57:56 by ahwang            #+#    #+#             */
/*   Updated: 2025/05/24 00:17:43 by ahwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

int	are_identical(char *s1, char *s2)
{
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	if (ft_strncmp(s1, s2, ft_strlen(s1)))
		return (0);
	return (1);
}

void	print_fractol_list(void)
{
	ft_printf("╔═════════════════════════════════════════╗\n");
	ft_printf("║         available fractal list          ║\n");
	ft_printf("╠═════════════════════════════════════════╣\n");
	ft_printf("║         1. mandelbrot                   ║\n");
	ft_printf("║         2. julia                        ║\n");
	ft_printf("╚═════════════════════════════════════════╝\n");
	ft_printf("\n");
	ft_printf("command: ./fractol FRACTAL");
	ft_printf(" (-1 <= JULIA_REAL <= 1) (-1 <= JULIA_IMAG <= 1)\n");
	ft_printf("\n");
	ft_printf("example: ./fractol mandelbrot\n");
	ft_printf("example: ./fractol 1\n");
	ft_printf("         ./fractol JULIA 0.222 0.333\n");
	ft_printf("         ./fractol Julia 0.333 0.444\n");
}

void	print_guide(void)
{
	ft_printf("╔════════════════════════════════╗\n");
	ft_printf("║       for every fractal        ║\n");
	ft_printf("╠═════════════╦══════════════════╣\n");
	ft_printf("║ SCROLL_UP   ║ zoom in          ║\n");
	ft_printf("║ SCROLL_DOWN ║ zoom out         ║\n");
	ft_printf("║ KEY_ESC     ║ exit             ║\n");
	ft_printf("║ KEY_C       ║ change color     ║\n");
	ft_printf("╠═════════════╩══════════════════╣\n");
	ft_printf("║         for julia set          ║\n");
	ft_printf("╠═════════════╦══════════════════╣\n");
	ft_printf("║ KEY_A       ║ real num: -      ║\n");
	ft_printf("║ KEY_D       ║ real num: +      ║\n");
	ft_printf("║ KEY_S       ║ imaginary num: - ║\n");
	ft_printf("║ KEY_W       ║ imaginary num: + ║\n");
	ft_printf("╚═════════════╩══════════════════╝\n");
}
