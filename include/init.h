#ifndef INIT_H
#define INIT_H

# include "../minilibx-linux/mlx.h"	///< MLX library
# include <stdio.h>	///< Will use it for bugs search
# include <unistd.h>


	/// Main functions
void	*init_mlx(void **);	///< Initialize the MLX and pass pointer to pointer of the window address from main()

	/// TODO Additional functions

	/// Learning functions
void	square_full(void *, void *);	///< Draw a filled square
void	square_outline(void *, void *);
void	square_fill(void *mlx_ptr, void *win_ptr);	/// TODO: Full square, pixels grow from xy both up and right
void	circle_outline(void *mlx_ptr, void *win_ptr);	/// TODO: Circle outline
void	spiral_squary(void *, void *);	///< Draw square pixels into a spiral
void	spiral(void *, void *);	/// TODO: Spiraling pixels outwards/inwards

#endif