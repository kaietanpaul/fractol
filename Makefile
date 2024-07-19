NAME = fractol

CC = gcc
MLX = -Lminilibx-linux -Lmlx -lmlx -Imlx -lXext -lX11 -lm -lz


SRCS = src/main.c src/init.c src/learning.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

