/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpaul <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:53:11 by kpaul             #+#    #+#             */
/*   Updated: 2024/09/03 16:53:19 by kpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <stdio.h>
///< stdio is for perror | stdlib for NULL, malloc, free, exit.
typedef struct s_atof
{
	double	result;
	double	sign;
	double	fraction;
	double	divisor;
	int		is_fraction;
}							t_atof;

typedef struct s_detail
{
	int		max_iter;
	int		end_color;
	int		red;
	int		green;
	int		blue;
	int		start_red;
	int		start_green;
	int		start_blue;
	int		end_red;
	int		end_green;
	int		end_blue;
	double	grad_start;
	double	grad_end;
	double	t;
	double	scaled_iter;
}							t_detail;

typedef struct s_complex
{
	double	real;
	double	imag;
}							t_complex;

typedef struct s_minmax
{
	double	real_min;
	double	real_max;
	double	imag_min;
	double	imag_max;
}							t_minmax;

typedef struct s_image
{
	void	*img;
	char	*pixel_start;
	int		bits_per_pixel;
	int		line_size;
	int		pixel_order;
}							t_image;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	char		*name;
	int			width;
	int			height;
	t_image		img;
	t_minmax	minmax;
	t_complex	comp;
	t_detail	detail;
	t_atof		atof;
}							t_mlx;

t_mlx		*init_mlx_win_img(t_mlx *data, int x, int y, char *title);

int			key_event(int keysym, t_mlx *data);
int			mouse_event(int button, int x, int y, t_mlx *data);

void		render_mandelbrot(t_mlx *data, t_minmax minmax, int max_iter);
int			mandelbrot(t_complex c, int max_iter);
void		render_julia(t_mlx *dt, t_complex j_const, t_minmax mm, int m_iter);
int			julia(t_complex z, t_complex julia_const, int max_iter);
int			color_gradient(t_detail detail, int iter, int m_iter, int s_color);

double		scale(double num, double old_max, double new_min, double new_max);
double		r_comp(int x, int width, double real_min, double real_max);
double		i_comp(int y, int height, double imag_min, double imag_max);

int			my_strcmp(char *s1, char *s2);
int			is_float(char *str);
double		my_atof(char *str);

int			clean_exit(t_mlx *data);
void		perror_exit(char *str, t_mlx *data);

#endif
