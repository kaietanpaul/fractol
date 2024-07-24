#include "../include/init.h"

/**
 * @brief The main function of the program.
 *
 * This function initializes the MLX library, creates a new window, and starts the MLX loop.
 * It serves as the entry point of the program.
 *
 * @return Exit status.
 */


//int main()
//{
//    t_data *data;
//
//	data = init_mlx();
//    if (!data)
//		return (1);	/// Initialization failed
//
//    make_line(data->mlx_ptr, data->win_ptr, 100, 200, 200, 0, 0xFF69B4);
//    mlx_loop(data->mlx_ptr);
//
//    return 0;
//}

typedef struct s_mlx_data	///< Contain basic pointer for the program
{
	void	*mlx_ptr;
	struct	s_window		///< Contains pointers for the window and it's successors
	{
		void			*win_ptr;
		struct s_window	*next;
	}							window;
}								t_mlx_data;

int	close_window(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape) {
		printf("Keycode:%d  Esc was clicked\n\n", keysym);
		mlx_destroy_window(data->mlx_ptr, data->window.win_ptr);    /// Destroy window
		exit(1);
	}
	printf("Keycode:%d   Key was clicked\n", keysym);
	return (0);
}

int main(void)
{
	t_mlx_data data;	///< Reference to data struct

	data.mlx_ptr = mlx_init();	///< Initiating connection

	data.window.win_ptr = mlx_new_window(data.mlx_ptr, 500, 500, "Win1");	///< Made window

	data.window.next = malloc(sizeof(struct s_window));	///< Allocating memory for next window
	if (data.window.next)	///< Check if was made
	{
		data.window.next->win_ptr = mlx_new_window(data.mlx_ptr, 200, 200, "Win2");	///< Made window
		data.window.next->next = NULL;	///< Set next window as NULL to signal end
	}

	mlx_key_hook(data.window.win_ptr, close_window, &data);

	mlx_loop(data.mlx_ptr);	///< Start the loop to keep the window(s) open

	mlx_destroy_window(data.mlx_ptr, data.window.next->win_ptr);	/// Destroy window
	free(data.window.next);
	mlx_destroy_display(data.mlx_ptr);	/// Destroy connection

	return (0);
}
