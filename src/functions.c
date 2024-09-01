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
	return (0);
}

int	is_float(char *str)
{
	int	has_decimal = 0;
	int	has_digit = 0;

	if (*str == '-')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			has_digit = 1;
		}
		else if (*str == '.' && !has_decimal)
		{
			has_decimal = 1;
		}
		else
		{
			return (0);
		}
		str++;
	}
	return (has_digit);
}

double	my_atof(char *str)
{
	double	result = 0.0;
	double	sign = 1.0;
	double	fraction = 0.0;
	double	divisor = 10.0;
	int		is_fraction = 0;

	if (*str == '-')
	{
		sign = -1.0;
		str++;
	}
	while (*str)
	{
		if (*str == '.')
		{
			is_fraction = 1;
			str++;
			continue;
		}
		if (*str >= '0' && *str <= '9')
		{
			if (is_fraction)
			{
				fraction += (*str - '0') / divisor;
				divisor *= 10.0;
			}
			else
				result = result * 10.0 + (*str - '0');
		}
		str++;
	}
	return (sign * (result + fraction));
}