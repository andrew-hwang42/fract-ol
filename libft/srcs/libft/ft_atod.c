/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahwang <ahwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:56:30 by ahwang            #+#    #+#             */
/*   Updated: 2025/05/24 20:30:07 by ahwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

int	check_valid_atod(int c)
{
	return (c == '+' || c == '-' || c == '.' || ('0' <= c && c <= '9'));
}

int	check_valid_str_atod(const char *str)
{
	int	i;
	int	point;

	i = 0;
	while (i < (int)ft_strlen(str))
	{
		if (!check_valid_atod(str[i++]))
			return (1);
	}
	if (str[0] == '.' || str[ft_strlen(str) - 1] == '.')
		return (1);
	i = 0;
	point = 0;
	while (i < (int)ft_strlen(str))
	{
		if (str[i] == '.')
			point++;
		i++;
	}
	if (point > 1)
		return (1);
	return (0);
}

int	atod_decimal_point(const char **str, int *cnt_zero, double *decimal_point)
{
	if (**str == '.')
		(*str)++;
	while ('0' <= **str && **str <= '9')
	{
		(*decimal_point) = (*decimal_point) * 10 + (*(*str)++ - '0');
		(*cnt_zero)++;
	}
	if (**str == '+' || **str == '-')
		return (1);
	while ((*cnt_zero)-- || *decimal_point >= 1)
		(*decimal_point) /= 10;
	return (0);
}

double	ft_atod_start(const char *str)
{
	int		sign;
	int		nbr;
	int		cnt_zero;
	double	decimal_point;

	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	nbr = 0;
	while ('0' <= *str && *str <= '9')
		nbr = nbr * 10 + (*str++ - '0');
	if (*str == '+' || *str == '-')
		return (ERROR_FT_ATOD);
	cnt_zero = 0;
	decimal_point = 0;
	if (atod_decimal_point(&str, &cnt_zero, &decimal_point))
		return (ERROR_FT_ATOD);
	return (sign * (nbr + decimal_point));
}

double	ft_atod(const char *str)
{
	if (check_valid_str_atod(str))
		return (ERROR_FT_ATOD);
	else
		return (ft_atod_start(str));
}
