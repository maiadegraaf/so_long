NAME	=	so_long

SRCS	=	./src/so_long.c \
			./src/t_map_utils.c \
			./src/generate_map.c \
			./src/create_img.c \
			./src/key_hook.c \
			./src/tools_tools.c \
			./src/my_mlx_pixel_put.c \
			./src/t_bugs_utils.c \
			./src/bugs.c \
			./src/tarantula.c \
			./src/loop.c \
			./src/init_info.c \
			./src/draw_info.c \
			./src/enemy.c \
			./src/enemy_utils.c \
			./src/utils_bonus.c \
			./src/img_utils.c \
			./src/initiate_enemy.c \
			./src/end_game.c

FLAGS	=	-Wall -Werror -Wextra -Imlx -g

LIBFT	=	libraries/libft/libft.a

MLX		=	libraries/mlx/libmlx.dylib

HEADER	=	includes/so_long.h

OBJS	=	$(SRCS:%.c=%.o)

all: $(LIBFT) $(MLX) $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) -g -fsanitize=address $^ -o $(NAME)
 
%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C libraries/libft

$(MLX):
	$(MAKE) -C libraries/mlx && test -e libmlx.dylib || ln -sf libraries/mlx/libmlx.dylib libmlx.dylib 

clean:
	make fclean -C libraries/libft
	make clean -C libraries/mlx
	rm -f $(OBJS)
	rm -f libmlx.dylib

fclean: clean
	rm -f $(MLX)
	rm -f $(LIBFT)
	rm -f $(NAME)

re: fclean all