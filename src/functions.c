/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpaul <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:53:55 by kpaul             #+#    #+#             */
/*   Updated: 2024/09/03 16:53:57 by kpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	my_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (1);
		s1++;
		s2++;
	}
	if (*s1 == '\0' && *s2 == '\0')
		return (0);
	return (1);
}

int	is_float(char *str)
{
	int	has_decimal;

	has_decimal = 0;
	if (*str == '-')
		str++;
	while (*str)
	{
		if (*str == '.')
		{
			if (has_decimal)
				return (0);
			has_decimal = 1;
		}
		else if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

double	my_atof(char *str)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0.0;
	sign = 1;
	pow = 1.0;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		integer_part = integer_part * 10 + (*str++ - '0');
	if (*str == '.')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		pow /= 10.0;
		fractional_part += (*str++ - '0') * pow;
	}
	return (sign * (integer_part + fractional_part));
}

int	clean_exit(t_mlx *data)
{
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
	exit(0);
}

void	perror_exit(char *str, t_mlx *data)
{
	perror(str);
	clean_exit(data);
}
