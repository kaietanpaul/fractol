#ifndef INIT_H
#define INIT_H

# include "../minilibx-linux/mlx.h"	///< MLX library
# include <math.h>	///< Will use it for mathematical functions

# include <stdio.h>	///< Will use it for bugs search
# include <unistd.h>	///< Will use it for bugs search

typedef struct s_data
{
	void	*mlx_ptr;	///< MLX instance ptr
	void	*win_ptr;	///< Window instance ptr
}	t_data;

typedef struct s_image
{
	void	*img_ptr;	///< Image instance ptr
	char	*addr;	///< Address of the image
	int		bits_per_pixel;	///< Bits per pixel
	int		size_line;	///< Size of the line
	int		endian;	///< Endian
}	t_image;


	/// Main functions
void	*init_mlx(void **);	///< Initialize the MLX and pass pointer to pointer of the window address from main()

	/// TODO Additional functions
void	*init_image(void *mlx_ptr, int width, int height);	///< Initialize an image
void	*get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);	///< Get data address
int		put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);	///< Put an image to the window
int		get_color_value(void *mlx_ptr, int color);	///< Get color value


	/// Learning functions
void	square_full(void *, void *);	///< Draw a filled square
void	square_outline(void *, void *);	///< Draw a square outline
void	spiral_squary(void *, void *);	///< Draw square pixels into a spiral
void	make_line(void *mlx_ptr, void *win_ptr, int line_len, int x, int y, int direction, int color);	///< Draw a line

	/// TODO Additional learning functions
void	spiral(void *, void *);	/// TODO: Spiraling pixels outwards/inwards
void	square_fill(void *mlx_ptr, void *win_ptr);	/// TODO: Full square, pixels grow from xy both up and right
void	circle_outline(void *mlx_ptr, void *win_ptr);	/// TODO: Circle outline, pixels grow from xy both up and right
void	circle_fill(void *mlx_ptr, void *win_ptr);	/// TODO: Full circle, pixels grow from xy both up and right
void	triangle_outline(void *mlx_ptr, void *win_ptr);	/// TODO: Triangle outline, pixels grow from xy both up and right
void	triangle_fill(void *mlx_ptr, void *win_ptr);	/// TODO: Full triangle, pixels grow from xy both up and right
void	rectangle_outline(void *mlx_ptr, void *win_ptr);	/// TODO: Rectangle outline, pixels grow from xy both up and right
void	rectangle_fill(void *mlx_ptr, void *win_ptr);	/// TODO: Full rectangle, pixels grow from xy both up and right
void	ellipse_outline(void *mlx_ptr, void *win_ptr);	/// TODO: Ellipse outline, pixels grow from xy both up and right
void	ellipse_fill(void *mlx_ptr, void *win_ptr);	/// TODO: Full ellipse, pixels grow from xy both up and right
void	polygon_outline(void *mlx_ptr, void *win_ptr);	/// TODO: Polygon outline, pixels grow from xy both up and right
void	polygon_fill(void *mlx_ptr, void *win_ptr);	/// TODO: Full polygon, pixels grow from xy both up and right
void	star_outline(void *mlx_ptr, void *win_ptr);	/// TODO: Star outline, pixels grow from xy both up and right
void	star_fill(void *mlx_ptr, void *win_ptr);	/// TODO: Full star, pixels grow from xy both up and right
void	heart_outline(void *mlx_ptr, void *win_ptr);	/// TODO: Heart outline, pixels grow from xy both up and right
void	heart_fill(void *mlx_ptr, void *win_ptr);	/// TODO: Full heart, pixels grow from xy both up and right
void	arrow_outline(void *mlx_ptr, void *win_ptr);	/// TODO: Arrow outline, pixels grow from xy both up and right
void	arrow_fill(void *mlx_ptr, void *win_ptr);	/// TODO: Full arrow, pixels grow from xy both up and right
void	cloud_outline(void *mlx_ptr, void *win_ptr);	/// TODO: Cloud outline, pixels grow from xy both up and right
void	cloud_fill(void *mlx_ptr, void *win_ptr);	/// TODO: Full cloud, pixels grow from xy both up and right

#endif