#ifndef INIT_H
# define INIT_H
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <X11/keysym.h>
# include <stdlib.h>

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
/// Struct to hold complex values
typedef struct s_complex
{
	double	real;
	double	imag;
}							t_complex;
/// Struct to hold min and max values for imaginary and real parts
typedef struct s_minmax
{
	double 	real_min;
	double 	real_max;
	double 	imag_min;
	double 	imag_max;
}							t_minmax;
///< Struct to hold image-related data
typedef struct s_image
{
	void	*img;			///< Pointer to the image object
	char	*pixel_start;		///< Pointer to the first pixel (start of pixel data)
	int		bits_per_pixel;		///< Number of bits used for each pixel
	int		line_size;			///< Size in bytes of one row of the image
	int		pixel_order;		///< Endianness of pixel data, 0 for little endian, 1 for big endian
}							t_image;
///< Struct to hold overall program data
typedef struct s_mlx
{
	void    *mlx;           ///< Pointer to MLX connection
	void    *win;           ///< Pointer to a window
	char    *name;
	int     width;
	int     height;
	t_image img;                ///< Image data structure
	t_minmax minmax;            ///< Min/Max boundaries for fractal
	t_complex comp;	      ///< Julia constant for the Julia set
	t_detail detail;			///< Details
}                           t_mlx;

t_mlx		*init_mlx_win_img(t_mlx *data, int x, int y, char *title);

int			key_event(int keysym, t_mlx *data);
int			mouse_event(int button, int x, int y, t_mlx *data);

void 		render_mandelbrot(t_mlx *data, t_minmax minmax, int max_iter);
int			mandelbrot(t_complex c, int max_iter);
void		render_julia(t_mlx *data, t_complex julia_const, t_minmax minmax, int max_iter);
int			julia(t_complex z, t_complex julia_const, int max_iter);
int			color_gradient(t_detail detail,int iter, int max_iter, int start_color);

double		scale(double num, double old_max, double new_min, double new_max);
double		r_comp(int x, int width, double real_min, double real_max);
double		i_comp(int y, int height, double imag_min, double imag_max);

int			my_strcmp(char *s1, char *s2);
int			is_float(char *str);
double		my_atof(char *str);

#endif