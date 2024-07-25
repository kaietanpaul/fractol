#include "../../include/init.h"

typedef struct s_mlx_data	///< Contain basic pointer for the program
{
	void	*mlx_ptr;
	struct	s_window		///< Contains pointers for the window and it's successors
	{
		void			*win_ptr;
		struct s_window	*next;
	}							window;
}								t_mlx_data;

int	close_window(int keysym, const t_mlx_data *data)
{
	if (keysym == XK_Escape) {
		printf("Keycode:%d  Esc was clicked\n\n", keysym);
		struct s_window *current = &data->window;
		while (current != NULL) {
			if (current->win_ptr != NULL) {
				mlx_destroy_window(data->mlx_ptr, current->win_ptr);
				current->win_ptr = NULL;	///< Clear the window pointer after destruction
			}
			struct s_window *next = current->next;	///< Save next pointer
			if (current != &data->window)	///< Do not free the embedded window structure
			{
				free(current);	///< Free the dynamically allocated window struct
			}
			current = next;	///< Move to the next window
		}

		mlx_destroy_display(data->mlx_ptr);	/// Destroy connection
		free(data->mlx_ptr);
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
	mlx_key_hook(data.window.next->win_ptr, close_window, &data);

	mlx_loop(data.mlx_ptr);	///< Start the loop to keep the window(s) open

	return (0);
}